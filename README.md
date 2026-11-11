*This project has been created as part of the 42 curriculum by ilazerou.*

# ft_printf

## Description

ft_printf is a project from the 42 curriculum in which we recreate the behavior of the C standard library function `printf`. The function formats its arguments according to a format string and writes the result to the standard output.

The main objective is to strengthen our understanding of C programming, especially variadic functions, recursion, and type handling. This project also teaches us how to split a problem into small reusable functions and how a formatted output function works internally.

### Function Prototype

    int ft_printf(const char *format, ...);

It returns the number of characters printed, or `-1` on error (for example, when `format` is `NULL` or when the format string ends with a lone `%`).

### Library Description

`libftprintf.a` is a static library containing the compiled object files of the project. It can be linked to other C programs and reused in future projects.

To display the contents of the library archive, use the following command:

    ar -t libftprintf.a

### Supported Conversions

- `%c`: prints a single character.
- `%s`: prints a string. If the pointer is `NULL`, `(null)` is printed.
- `%p`: prints a pointer address in hexadecimal, prefixed with `0x`. If the pointer is `NULL`, `(nil)` is printed.
- `%d`: prints a signed decimal integer.
- `%i`: prints a signed decimal integer.
- `%u`: prints an unsigned decimal integer.
- `%x`: prints an unsigned integer in lowercase hexadecimal.
- `%X`: prints an unsigned integer in uppercase hexadecimal.
- `%%`: prints a percent sign.

### Project Structure

- `ft_printf.c`: contains `ft_printf` and the conversion dispatcher.
- `ft_putchar.c`: prints one character.
- `ft_putstr.c`: prints a string and handles `NULL`.
- `ft_putnbr.c`: prints a signed integer.
- `ft_putunsignedn.c`: prints an unsigned integer.
- `ft_puthex.c`: prints a number in hexadecimal, in lowercase or uppercase.
- `ft_putaddress.c`: prints a pointer address.
- `ft_printf.h`: contains the includes and the function prototypes.

## Instructions

### Requirements

The following tools are required to compile the library:

- A C compiler, such as `cc`.
- `make` to automate the compilation process.
- `ar` to create and manage the static library archive.

### Installation

Clone the repository:

    git clone git@vogsphere-v2-bg.1337.ma:vogsphere/intra-uuid-21d8e98d-9bea-47dc-9562-ae2b24270074-7789977-ilazerou ft_printf

Enter the project directory:

    cd ft_printf

### Compilation

To compile the library, run:

    make

This command compiles the source files with the flags `-Wall -Wextra -Werror` and creates the static library `libftprintf.a`.

The Makefile provides the following rules:

- `make`: Compiles the library.
- `make clean`: Removes the compiled object files.
- `make fclean`: Removes the object files and the library archive.
- `make re`: Cleans the previous build and recompiles the library.

### Using the Library

Once compiled, `libftprintf.a` can be linked to your C programs. Include the header file and link the library during compilation.

Example of a program:

    #include "ft_printf.h"

    int main(void)
    {
        int count;

        count = ft_printf("Hello %s, number: %d, hex: %x\n", "42", 42, 255);
        ft_printf("Characters printed: %d\n", count);
        return (0);
    }

To compile a program with ft_printf, use:

    cc -Wall -Wextra -Werror main.c libftprintf.a -o test

Run the resulting executable with:

    ./test

## Algorithm and Data Structure

### Overall Approach

`ft_printf` reads the format string one character at a time, in a single pass:

1. If the current character is not `%`, it is printed as it is.
2. If the current character is `%`, the next character is the conversion specifier. It is passed to a dispatcher function (`put_type`), which calls the matching print function.
3. Every print function returns the number of characters it printed. `ft_printf` adds these values into one counter, which is the final return value.

### Justification of the Choices

- Variadic arguments (`va_list`): the number and the types of the arguments are unknown at compile time. The macros `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` allow us to read the arguments one by one, in order. No other data structure is needed, because the format string is processed linearly and each argument is consumed once.
- One function per conversion: each conversion is isolated in its own small function. This keeps the code readable, respects the Norm, and makes each part easy to test separately.
- Returning the printed count: every function returns the number of characters it wrote. This avoids computing lengths a second time and keeps `ft_printf` simple.
- Recursion for numbers: digits are computed from the least significant to the most significant (`nb % base`), but they must be printed in the opposite order. Recursion solves this without a buffer: the function first calls itself with `nb / base`, then prints the current digit. The same idea is used for decimal and hexadecimal numbers, only the base changes. For hexadecimal, a lookup string (`"0123456789abcdef"` or `"0123456789ABCDEF"`) converts a digit into its character.
- `long` for signed integers: negating `INT_MIN` would overflow an `int`. Converting the value to `long` before the negation handles this case safely.
- `unsigned long` for addresses: a pointer is 64 bits wide on modern systems, so it is stored in an `unsigned long` to avoid truncation before being printed in hexadecimal.
- `int` for `%c`: in a variadic function, a `char` argument is promoted to `int` (default argument promotions). Therefore `va_arg(args, int)` is used for `%c`.

### Edge Cases Handled

- `%s` with `NULL` prints `(null)`.
- `%p` with `NULL` prints `(nil)`.
- `%c` with `0` prints a null byte, and it is counted.
- `%d` with `INT_MIN` and `INT_MAX`.
- `%u` and `%x` with `0` and with the maximum `unsigned int` value.
- `%%` prints a single `%`.
- A `NULL` format, or a format ending with a lone `%`, returns `-1`.

## Design Choices

The library is built around several important principles:

- Modularity: each function has a specific purpose, making the code easier to understand and maintain.
- Consistency: the output and the return value should reproduce the behavior of the original `printf` for the supported conversions.
- Memory safety: no dynamic allocation is used, so there is no risk of memory leaks.
- Coding standards: the project follows the applicable 42 Norm requirements.

## Learning Objectives

This project provides practical experience with fundamental C programming concepts, including:

- Understanding variadic functions and the `stdarg.h` macros.
- Understanding default argument promotions.
- Using recursion to convert numbers to a given base.
- Handling edge cases such as `NULL` pointers and `INT_MIN`.
- Building and using static libraries.
- Writing modular and reusable functions.

## Resources

The following resources are useful for understanding variadic functions and the behavior of `printf`:

- Linux man-pages: https://man7.org/linux/man-pages/
- cppreference — Variadic functions: https://en.cppreference.com/w/c/variadic
- cppreference — Formatted output (`printf`): https://en.cppreference.com/w/c/io/fprintf
- GNU C Library Manual: https://www.gnu.org/software/libc/manual/
- 42 Intranet: Project instructions and evaluation guidelines.

### Use of Artificial Intelligence

AI tools were used as supplementary learning resources during this project for the following purposes:

- Understanding variadic functions, `va_list`, and default argument promotions.
- Getting hints to debug problems (for example, a segmentation fault with `NULL` strings, return values of the print functions, and the types used for `%u` and `%p`).
- Getting suggestions for test cases and edge cases to compare with the original `printf`.
- Organizing and improving the project documentation.

AI assistance was used to support learning and understanding. The code of the project was written and tested by me.

## Author

- Login: ilazerou
- Project: ft_printf
- School: 42