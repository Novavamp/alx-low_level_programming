0x14. C - Bit Manipulation

Welcome to the "0x14. C - Bit Manipulation" repository at Holberton School. This collection of C programs aims to explore and practice various bit manipulation techniques in C programming.

Bit manipulation involves working with individual bits in a binary number, utilizing bitwise operators. In this repository, we will focus on the following common bitwise operators for bit manipulation:

& (AND): Performs a bitwise AND operation on two numbers, resulting in a number with bits set to 1 only if both input bits are 1.
| (OR): Performs a bitwise OR operation on two numbers, producing a number with bits set to 1 if either input bit is 1.
^ (XOR): Executes a bitwise XOR operation on two numbers, generating a number with bits set to 1 if the input bits are different.
~ (NOT): Applies a bitwise NOT operation to a number, inverting all the bits (0 becomes 1 and 1 becomes 0).
<< (left shift): Shifts the bits of a number to the left by a certain number of positions, padding 0s on the right.
>> (right shift): Shifts the bits of a number to the right by a certain number of positions, padding 0s on the left.

Programs in the Repository:

1. `binary_to_uint.c`: Converts a binary string to an unsigned integer. The binary string is provided as an argument to the `binary_to_uint` function, which returns the corresponding unsigned integer. If the input string is not a valid binary number, the function returns 0.

2. `print_binary.c`: Prints the binary representation of a number. The number is passed as an argument to the `print_binary` function, which prints the binary digits from the most significant bit to the least significant bit.

3. `get_bit.c`: Retrieves the value of a bit at a certain index in a number. The number and index are passed as arguments to the `get_bit` function, which returns the value of the bit at the specified index (either 0 or 1).

4. `set_bit.c`: Sets the value of a bit at a certain index in a number to 1. The number and index are provided as arguments to the `set_bit` function, which sets the bit at the specified index to 1 and returns the updated number.

5. `clear_bit.c`: Sets the value of a bit at a certain index in a number to 0. The number and index are passed as arguments to the `clear_bit` function, which sets the bit at the specified index to 0 and returns the updated number.

6. `flip_bits.c`: Calculates the number of bits that need to be flipped to convert one number to another. The two numbers are given as arguments to the `flip_bits` function, which returns the count of differing bits between the two numbers.

How to Use:

To use these programs, you'll need a C compiler like gcc. Follow these steps:

1. Clone this repository to your local machine.
2. Compile the programs using the following command:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o program_name
```
Replace `program_name` with the name of the specific program you want to compile (e.g., `binary_to_uint`).
