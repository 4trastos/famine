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
# include <errno.h>
# include <fcntl.h>
# include <ctype.h>
# include <pwd.h>

# define SINGATURE "Famine version 1.0 (c)oded by davgalle"

typedef struct s_sh_type
{
    uint32_t    value;
    const char  *name;
    const char  *description;
} t_sh_type;

typedef struct s_version
{
    uint16_t    value;
    const char *name;
    const char *description;
} t_version;

typedef struct s_machine
{
    uint16_t    value;
    const char  *name;
    const char  *description;
} t_machine;

typedef struct s_type
{
    uint16_t    value;
    const char  *name;
    const char  *description;
}   t_type;

typedef struct s_ph_type
{
    uint32_t    value;
    const char  *name;
    const char  *description;
}   t_ph_type;

typedef struct s_famine
{
    size_t          file_size;
    int             fd;
    int             type;
    char            **env;
    const char      *file;
    unsigned char   *elf;
    char            *strtab;
    char            *type_name;
    Elf64_Ehdr      *header; 
    Elf64_Shdr      *sectab;
    struct passwd   *pwd;
    struct stat     file_info;
}   t_famine;

extern t_type g_t_type[];
extern t_machine g_t_machine[];
extern t_version g_t_version[];
extern t_sh_type g_s_sh_type[];
extern t_ph_type g_t_ph_type[];

/* FUNCTIONS */

int     main(int argc, char **argv, char **env);
int     ft_checkarg(t_famine *famine);
int     ft_readelf(t_famine *famine);
void    ft_printheader(t_famine *famine);
void    ft_pointer_section_table(t_famine *famine);
void    ft_pointer_strings_table(t_famine *famine);
void    ft_detect_prev_infection(t_famine *famine);

#endif