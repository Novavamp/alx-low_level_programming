#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 *
 * Return: Always 98
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    char *num1_str = argv[1];
    char *num2_str = argv[2];

    for (int i = 0; num1_str[i] != '\0'; i++) {
        if (!isdigit(num1_str[i])) {
            printf("Error\n");
            return 98;
        }
    }

    for (int i = 0; num2_str[i] != '\0'; i++) {
        if (!isdigit(num2_str[i])) {
            printf("Error\n");
            return 98;
        }
    }

    int num1 = atoi(num1_str);
    int num2 = atoi(num2_str);

    if (num1 <= 0 || num2 <= 0) {
        printf("Error\n");
        return 98;
    }

    int result = num1 * num2;

    printf("%d\n", result);

    return 0;
}

