#include <stdio.h>

// reverse striing using recursion

void reverse_string(char *str) {
    if (*str == '\0') {
        return;
    }
    reverse_string(str + 1);
    printf("%c", *str);
}

int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("\n");
    return 0;
}