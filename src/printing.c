#include "../incl/famine.h"

void    ft_pointer_strings_table(t_famine *famine)
{
    famine->strtab = (char *)(famine->elf + famine->sectab[famine->header->e_shstrndx].sh_offset);
}

void    ft_pointer_section_table(t_famine *famine)
{
    famine->sectab = (Elf64_Shdr *)(famine->elf + famine->header->e_shoff);
}

void    ft_printheader(t_famine *famine)
{
    int i = 0;
    int j = 0;
    int flag = 0;
    while (g_t_type[i].name && flag == 0)
    {
        if (g_t_type[i].value == famine->header->e_type)
        {
            printf("Type: [ %s - %s ]\n", g_t_type[i].name, g_t_type[i].description);
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
            printf("Machine: [ %s - %s ]\n", g_t_machine[i].name, g_t_machine[i].description);
            flag = 1;
        }
        i++;
    }
   
    printf("Header size:     [ %d bytes ]\n", famine->header->e_ehsize);
    printf("Sections:        [ %d ]\n",       famine->header->e_shnum);
    printf("Sections offset: [ %lu ]\n",      famine->header->e_shoff);
    printf("Str section idx: [ %d ]\n",       famine->header->e_shstrndx);
    printf("Segments:        [ %d ]\n",       famine->header->e_phnum);
    printf("Segments offset: [ %lu ]\n",      famine->header->e_phoff);
    printf("\n*** SECTIONS ***\n\n");

    i = 0;
    flag = 0;
    while (i < famine->header->e_shnum)
    {   
        j = 0;
        flag = 0;
        famine->type_name = "UNKNOWN";
        while (g_s_sh_type[j].name && flag == 0)
        {
            if (g_s_sh_type[j].value == famine->sectab[i].sh_type)
            {
                famine->type_name = (char *)g_s_sh_type[j].name;
                flag = 1;
            }
            j++;
        }
        printf("[%2d] %-20s %-20s Size [%4lu] Offset [%5lu]\n", i, famine->strtab + famine->sectab[i].sh_name, famine->type_name,
            famine->sectab[i].sh_size, famine->sectab[i].sh_offset);
        i++;
    }
    
}