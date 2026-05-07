*This activity has been created as part of the 42 curriculum by <ytrabels>.*

# ft_printf

## Description

This project is a reimplementation of the C standard library function `printf()`. The goal is to build a static library `libftprintf.a` that exposes a `ft_printf()` function mimicking the behavior of the original, without implementing its internal buffer management.

The project introduces **variadic functions** in C — functions that accept a variable number of arguments — through the use of `va_start`, `va_arg`, `va_copy`, and `va_end` from `<stdarg.h>`.

Supported conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in hexadecimal lowercase |
| `%X` | Prints a number in hexadecimal uppercase |
| `%%` | Prints a literal percent sign |

## Instructions

### Compilation

```bash
make
```

This will compile the source files and create `libftprintf.a` at the root of the repository.

### Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

Then link against the library when compiling your project:

```bash
cc your_file.c -L. -lftprintf -o your_program
```

### Makefile rules

| Rule | Effect |
|------|--------|
| `make` / `make all` | Builds `libftprintf.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` then `all` |

## Project Structure

```
.
├── ft_printf.c          # Entry point: format string parser + dispatcher
├── ft_printf.h          # Header: prototypes and includes
├── Makefile
├── libftprintf.a        # Compiled static library
└── func/
    ├── ft_putchar.c     # %c handler
    ├── ft_putstr.c      # %s handler
    ├── ft_putnbr.c      # %d, %i and %u handler
    ├── ft_putptr.c      # %p handler
    └── ft_convert_tohex.c  # %x and %X handler
```

## Algorithm and Data Structure

The core of `ft_printf` is a **format string parser** living in `ft_printf.c`. It iterates character by character over the format string:

- When a regular character is encountered, it is written directly to stdout via `ft_putchar`.
- When a `%` is encountered, the next character is read to identify the conversion specifier, and the corresponding function from the `func/` directory is called, pulling the next argument via `va_arg`.

Each conversion specifier is handled by a dedicated, single-responsibility function:

| File | Role |
|------|------|
| `ft_putchar.c` | Writes a single character (`%c`) |
| `ft_putstr.c` | Writes a null-terminated string (`%s`) |
| `ft_putnbr.c` | Handles signed and unsigned integers (`%d`, `%i`, `%u`) |
| `ft_convert_tohex.c` | Converts and prints numbers in hexadecimal (`%x`, `%X`) |
| `ft_putptr.c` | Casts the pointer to `unsigned long` and prints it as hex with `0x` prefix (`%p`) |

The function returns the total number of characters written, accumulated across all handler calls. No dynamic memory allocation is used, keeping the implementation lightweight and leak-free.

## Resources

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — Official printf documentation
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) — Variadic arguments in C
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — Detailed format specifier reference
