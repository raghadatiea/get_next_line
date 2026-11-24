*This project has been created as part of the 42 curriculum by ratieh.*

# get_next_line

## Description

The **get_next_line** project is part of the 42 curriculum. Its goal is to create a function that reads a file or input stream line by line.

The function returns one line at a time, including the newline character (`\n`) when it exists. It uses a static variable to preserve the remaining data between successive function calls.

This project introduces important concepts in C programming, including:

- File descriptors.
- The `read()` system call.
- Static variables.
- Dynamic memory allocation.
- String manipulation.
- Memory management.

## Instructions

### Compilation

The project must be compiled using a C compiler.

To compile the mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

You can change the `BUFFER_SIZE` value to test different buffer sizes.

### Execution

Run the program using:

```bash
./get_next_line
```

The function can read from a file or standard input, depending on the file descriptor passed to it.

### Function Prototype

```c
char *get_next_line(int fd);
```

The function returns:
- A line read from the file, including `\n` if present.
- `NULL` when there is nothing more to read or an error occurs.

## Resources

### Documentation and References

- [read() – Linux Manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() – Linux Manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/static.html)
- [C Programming Language – GNU Documentation](https://www.gnu.org/software/gnu-c-manual/)

### AI Usage

AI tools were used as learning and support resources during the development of this project.

They were used for:
- Understanding the project requirements and breaking down the problem.
- Explaining concepts such as static variables, file descriptors, and buffer management.
- Understanding how `read()`, `malloc()`, and string manipulation work.
- Debugging errors and reviewing code logic.
- Discussing edge cases and testing strategies.

The implementation was developed through practical coding, testing, and understanding the underlying concepts.