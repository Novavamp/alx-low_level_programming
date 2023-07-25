# File I/O in C

This repository contains a set of C programs demonstrating file input and output operations in Linux. These programs utilize the system calls `open()`, `close()`, `read()`, and `write()`.

## Program Descriptions

Below are the descriptions of the included files:

### [0-read_textfile.c](./0-read_textfile.c)

This program reads the content of a text file and prints it to the standard output.

### [1-create_file.c](./1-create_file.c)

This program creates a new file and writes text content into it.

### [2-append_text_to_file.c](./2-append_text_to_file.c)

This program appends text content to an existing file.

### [3-cp.c](./3-cp.c)

This program copies the content from one file to another.

## Usage

To compile any of the C programs in this repository, use the following command format:

```
gcc -Wall -Werror -Wextra -pedantic <filename>.c -o <output_filename>
```

To execute the compiled program, use the following command format:

```
./<output_filename> <input_file> <output_file>
```

For instance, to run the `0-read_textfile.c` program, use the following commands:

```
gcc -Wall -Werror -Wextra -pedantic 0-read_textfile.c -o readfile
./readfile test.txt
```

## Author

These programs were authored by Precious Gabraels as part of the ALX low-level programming and algorithm curriculum.
