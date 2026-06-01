#include "../incl/famine.h"

t_type g_t_type[] =
{
    {0,  "ET_NONE", "No file type"},
    {1,  "ET_REL",  "Relocatable file"},
    {2,  "ET_EXEC", "Executable file"},
    {3,  "ET_DYN",  "Shared object file"},
    {4,  "ET_CORE", "Core file"},
    {0,  NULL,      NULL}
};

t_machine g_t_machine[] =
{
    {3,   "EM_386",    "x86 32 bits"},
    {40,  "EM_ARM",    "ARM 32 bits"},
    {62,  "EM_X86_64", "x86 64 bits"},
    {183, "EM_AARCH64","ARM 64 bits"},
    {0,   NULL,        NULL}
};

t_version g_t_version[] =
{
    {0, "EV_NONE",    "Invalid"},
    {1, "EV_CURRENT", "Current version"},
    {0, NULL,         NULL}
};

t_sh_type g_s_sh_type[] =
{
    {0,  "SHT_NULL",      "Inactive"},
    {1,  "SHT_PROGBITS",  "Program data"},
    {2,  "SHT_SYMTAB",    "Symbol table"},
    {3,  "SHT_STRTAB",    "String table"},
    {4,  "SHT_RELA",      "Relocations with addends"},
    {5,  "SHT_HASH",      "Symbol hash table"},
    {6,  "SHT_DYNAMIC",   "Dynamic linking info"},
    {7,  "SHT_NOTE",      "Notes"},
    {8,  "SHT_NOBITS",    "No space in file (.bss)"},
    {9,  "SHT_REL",       "Relocations without addends"},
    {11, "SHT_DYNSYM",    "Dynamic symbol table"},
    {14, "SHT_INIT_ARRAY", "Array of constructors"},
    {15, "SHT_FINI_ARRAY", "Array of destroyers"},
    {1879048182, "SHT_GNU_HASH", "GNU hash table"},
    {1879048190, "SHT_GNU_verneed", "GNU version needed"},
    {1879048191, "SHT_GNU_versym", "GNU version symbol"},
    {0,  NULL,            NULL}
};

t_ph_type g_t_ph_type[] =
{
    {0, "PT_NULL",    "Unused"},
    {1, "PT_LOAD",    "Loadable segment"},
    {2, "PT_DYNAMIC", "Dynamic linking info"},
    {3, "PT_INTERP",  "Interpreter path"},
    {4, "PT_NOTE",    "Auxiliary info"},
    {6, "PT_PHDR",    "Program header table"},
    {7, "PT_TLS",     "Thread-local storage"},
    {0, NULL,         NULL}
};