#ifndef FAMINE_H
# define FAMINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <elf.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include <ctype.h>
# include <pwd.h>
# include <dirent.h>
# include <byteswap.h>

# define SIGNATURE "Famine version 1.0 (c)oded by davgalle"

typedef struct s_famine
{
    size_t          file_size;
    int             fd;
    int             type;
    int             valid;
    const char      *binary;
    char            *strtab;
    char            *type_name;
    void            *signd;
    unsigned char   *elf;
    int             bits;
    Elf64_Ehdr      *header; 
    Elf64_Shdr      *sectab;
    struct stat     file_info;
    struct dirent   *readdir;
    DIR             *dir;
}   t_famine;

/* FUNCTIONS */

int     ft_checkarg(t_famine *famine);
int     ft_readelf(t_famine *famine);
void    ft_pointer_section_table(t_famine *famine);
void    ft_pointer_strings_table(t_famine *famine);
void    ft_infect(t_famine *famine);
int     ft_detect_prev_infection(t_famine *famine);
char    *ft_setdir(int i);

#endif