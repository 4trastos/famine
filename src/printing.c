#include "../incl/famine.h"

void    ft_printheader(t_famine *famine)
{
    int i = 0;
    int flag = 0;
    while (g_t_type[i].name && flag == 0)
    {
        if (g_t_type[i].value == famine->header->e_type)
        {
            printf("Type: ( %s - %s )\n", g_t_type[i].name, g_t_type[i].description);
            flag = 1;
        }
        i++;
    }
    i = 0;
    flag = 0;
    while (g_t_machine[i].name && flag == 0)
    {
        if (g_t_machine[i].value == famine->header->e_machine)
        {
            printf("Machine: ( %s - %s )\n", g_t_machine[i].name, g_t_machine[i].description);
            flag = 1;
        }
        i++;
    }
    i = 0;
    flag = 0;
    while (g_s_sh_type[i].name && flag == 0)
    {
        if (g_s_sh_type[i].value == famine->header->e_shnum)
        {
            printf("Section types: ( %s - %s )\n", g_s_sh_type[i].name, g_s_sh_type[i].description);
            flag = 1;
        }
        i++;
    }
    printf("Header size:     ( %d bytes )\n", famine->header->e_ehsize);
    printf("Sections:        ( %d )\n",       famine->header->e_shnum);
    printf("Sections offset: ( %lu )\n",      famine->header->e_shoff);
    printf("Str section idx: ( %d )\n",       famine->header->e_shstrndx);
    printf("Segments:        ( %d )\n",       famine->header->e_phnum);
    printf("Segments offset: ( %lu )\n",      famine->header->e_phoff);
    printf("\n--- SECTIONS ---\n");
    
}