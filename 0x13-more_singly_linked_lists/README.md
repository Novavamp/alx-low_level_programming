# 0x13-Additional_Singly_Linked_Lists

The contents of this repository consist of C programs that exemplify the utilization of singly linked lists. These programs build upon the concepts presented in the preceding repository, [0x12-singly_linked_lists](https://github.com/USERNAME_HERE/holbertonschool-low_level_programming/tree/main/0x12-singly_linked_lists).

## Data Structure

Within this directory, the following structure is employed to represent a node in the linked list:

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

Each node holds an integer value, denoted as `n`, along with a pointer to the subsequent node in the list.

## File Contents

This repository includes the following files:

### `lists.h`

The header file containing function prototypes for all the functions used in this directory.

### `0-print_listint.c`

This file encompasses a function that prints all the elements of a `listint_t` linked list.

### `1-listint_len.c`

This file comprises a function that returns the count of elements in a `listint_t` linked list.

### `2-add_nodeint.c`

This file embodies a function that appends a new node at the beginning of a `listint_t` linked list.

### `3-add_nodeint_end.c`

This file features a function that adds a new node at the end of a `listint_t` linked list.

### `4-free_listint.c`

This file contains a function that deallocates a `listint_t` linked list.

### `5-free_listint2.c`

This file contains a function that frees a `listint_t` linked list and sets the head to `NULL`.

### `6-pop_listint.c`

This file includes a function that removes the head node of a `listint_t` linked list and returns the data stored in the former head node.

### `7-get_nodeint.c`

This file encompasses a function that retrieves the `n`th node of a `listint_t` linked list.

### `8-sum_listint.c`

This file embodies a function that computes the sum of all the data in a `listint_t` linked list.

### `9-insert_nodeint.c`

This file features a function that inserts a new node at a specified position within a `listint_t` linked list.

### `10-delete_nodeint.c`

This file contains a function that deletes a node at a given position within a `listint_t` linked list.

## Usage

To compile any of the C programs within this directory, employ the following command:

```
gcc -Wall -Werror -Wextra -pedantic <filename.c> -o <output>
```

Replace `<filename.c>` with the name of the C file you intend to compile and `<output>` with the desired name for the compiled program.

For instance, to compile `0-print_listint.c`, utilize the subsequent command:

```
gcc -Wall -Werror -Wextra -pedantic 0-print_listint.c -o print_listint
```

To execute the compiled program, utilize the subsequent command:

```
./<output>
```

Replace `<output>` with the name assigned to the compiled program.

For example, to run the compiled program `print_listint`, employ the following command:

```
./print_listint
```

This will execute the program and display the output in the terminal.

## Author

This directory is composed and maintained by Precious Okechukwu Nwosu.
