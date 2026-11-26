*This project has been created as part of the 42 curriculum by mbodin.*

# ft_printf

## Description

**ft_printf** is a foundational C programming project at 42. The goal is to recode the standard libc `printf()` function, creating a static library named `libftprintf.a`.

Through this project, the main objective is to discover and master **variadic functions** in C (using `<stdarg.h>`), while designing a clean, modular, and extensible codebase that adheres strictly to the 42 Norm. Once validated, this function can be integrated into `libft` for use in future C projects.

### Supported Conversions (Mandatory)

* `%c`: Prints a single character.
* `%s`: Prints a string (as defined by the common C convention).
* `%p`: Prints a `void *` pointer argument in hexadecimal format.
* `%d`: Prints a decimal (base 10) number.
* `%i`: Prints an integer in base 10.
* `%u`: Prints an unsigned decimal (base 10) number.
* `%x`: Prints a number in hexadecimal (base 16) lowercase format.
* `%X`: Prints a number in hexadecimal (base 16) uppercase format.
* `%%`: Prints a percent sign.

*(Note: If you implemented the bonus part, you can list the supported flags here: `-`, `0`, `.`, minimum field width, `#`, `+`, and space).*

## Instructions

### Compilation

The project includes a `Makefile` that compiles the source files using `cc` with the `-Wall`, `-Wextra`, and `-Werror` flags, and archives them into `libftprintf.a` using `ar`.

To compile the library, run at the root of the repository:

```bash
make
```

Other available Makefile rules:

* `make clean`: Removes all object files (`.o`).
* `make fclean`: Removes all object files and the compiled library (`libftprintf.a`).
* `make re`: Performs a full recompilation (`fclean` followed by `all`).
* `make bonus`: Compiles the library including the bonus features *(if applicable)*.

### Usage

To use `ft_printf` in your C project, include the header file and link the compiled library during compilation:

1. Include the header in your C file:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, Hex: %x\n", "42", 42, 42);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}
```

2. Compile your program with `libftprintf.a`:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

## Algorithm and Data Structure

### Chosen Algorithm

The implementation relies on a **linear single-pass parsing algorithm** combined with a **dispatcher pattern**:

1. **Variadic Initialization:** `ft_printf` initializes a `va_list` structure via `va_start` to iterate over the unknown number of arguments passed after the format string.
2. **Format String Traversal:** The function iterates character by character through the `const char *format` string.
   * If the current character is not `%`, it is written directly to the standard output (`fd = 1`) via `write()`, incrementing the total printed character counter.
   * If a `%` is encountered, the parser inspects the following character(s) to identify the conversion specifier.
3. **Conversion Dispatching:** Once a specifier (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) is identified, a dispatcher function (using conditional branching or a function pointer lookup table) extracts the next argument using `va_arg` with its appropriate data type and delegates formatting to a dedicated helper function.
4. **Base Conversion:** Numeric conversions (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) use recursive or iterative division/modulo algorithms to convert integers into their respective string representations (base 10 or base 16) without relying on dynamic buffer allocations, avoiding memory leaks and maximizing performance.

### Justification & Data Structure

* **Data Structure:** For the mandatory part, no complex heap-allocated data structures are needed—only the standard `va_list` macro type from `<stdarg.h>` is used to track argument pointers on the stack. *(If bonuses are implemented, a `t_flags` struct is used to store parsed flag states, width, and precision cleanly).*
* **Why this approach?** The subject explicitly forbids implementing the internal buffer management of the original `printf()`. Writing directly to `stdout` via `write()` keeps the memory footprint minimal ($O(1)$ space complexity), eliminates the risk of memory leaks, and ensures $O(N)$ time complexity where $N$ is the length of the formatted output. Splitting each conversion into small, single-responsibility functions also guarantees compliance with the 42 Norm (max 25 lines per function) and makes adding bonus flags modular.

## Resources

### Classic References

* **Linux Programmer's Manual:** `man 3 printf` and `man 3 stdarg` for official specifications on format specifiers, undefined behaviors, and variadic macros (`va_start`, `va_arg`, `va_end`).
* **42 Docs / Peer Resources:** Community guides on `ft_printf` edge cases (such as `NULL` strings `"(null)"`, `NULL` pointers `"(nil)"` or `"0x0"`, and `INT_MIN` handling).
* https://42-fran-byte-f94097.gitlab.io/docs/ft_printf/ft_printf-approach-en/#/
* https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf
* https://www.youtube.com/watch?v=FAcLmFhoDB4
* **CodeVault Youtube channel** https://www.youtube.com/watch?v=oDC208zvsdg

### AI Usage

In accordance with the 42 curriculum guidelines on AI usage:

* **Tasks & Parts:** AI tools were used strictly as a learning assistant to clarify the internal mechanics of `va_list` memory alignment, verify edge-case behaviors of the original `printf()` (e.g., passing `NULL` to `%s` and `%p`), and structure this `README.md` documentation.
* **Implementation:** All C source code, Makefile rules, and debugging were written and tested manually without AI-generated code, ensuring full ownership and understanding for peer-evaluation and exams.