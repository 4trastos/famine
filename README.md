# Famine — Project UNIX @ 42Network

> *"This project is about coding your first virus."*

##  Descripción

**Famine** es un virus ELF de 64 bits escrito en C que infecta binarios añadiendo una firma sin alterar su comportamiento original. Es el primer proyecto de la serie de virus de 42Network, que precede a Pestilence, War y Death.

El virus actúa en silencio — sin output, sin logs, sin errores visibles — sobre los binarios presentes en `/tmp/test` y `/tmp/test2`.

##  Objetivos

- Comprender el formato ELF64 a nivel binario
- Aprender a modificar binarios en ejecución sin romper su funcionalidad
- Implementar detección de infección previa (una sola infección por binario)
- Desarrollar código de bajo perfil: cero output en cualquier circunstancia

##  Funcionamiento

```
./Famine
```

Al ejecutarse, Famine recorre `/tmp/test` y `/tmp/test2`, identifica todos los binarios ELF de 64 bits y les inyecta la firma:

```
Famine version 1.0 (c)oded by <login>
```

El binario infectado conserva su comportamiento original — sigue funcionando exactamente igual que antes.

##  Conceptos técnicos

| Concepto | Descripción |
|----------|-------------|
| Formato ELF64 | Estructura de los ejecutables Linux: header, segments, sections |
| `mmap` | Mapeo de ficheros en memoria para modificarlos |
| Detección de infección | Búsqueda de la firma antes de infectar para evitar doble infección |
| Inyección en sección | Inserción de datos en una sección existente o nueva del binario |
| `opendir` / `readdir` | Recorrido de directorios para encontrar víctimas |

##  Estructura

```
Famine/
├── Makefile
├── includes/
│   └── famine.h
└── srcs/
    ├── main.c
    ├── elf_parser.c
    ├── infect.c
    └── scanner.c
```

##  Restricciones

- Solo actúa en `/tmp/test` y `/tmp/test2` — nunca fuera
- Un único binario solo puede infectarse una vez
- Sin output en stdout ni stderr bajo ninguna circunstancia
- Escrito en C o ASM únicamente
- Requiere VM con Linux kernel > 3.14

##  Compilación

```bash
make
```

##  Entorno

- Linux 64 bits (Debian 7.0+)
- Kernel > 3.14
- VM obligatoria para desarrollo y evaluación

##  Lo que aprendes

Famine es la introducción práctica a la **virología informática**. Entender cómo un virus inyecta código en un binario sin romperlo es la base de todo lo que viene después — Pestilence (infección en cadena), War (detección), y Death (combinación avanzada).

```bash
docker run -it --rm \
  -v "$(pwd):/workspace" \
  -w /workspace \
  debian:bullseye \
  bash -c "apt update -qq && apt install -y build-essential binutils && bash"
```

---

*Proyecto realizado en el marco del cursus de ciberseguridad de 42Network Madrid.*