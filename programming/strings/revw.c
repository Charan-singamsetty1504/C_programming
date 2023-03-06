#include <stdio.h>
#include <string.h>

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[100];
    char buffer[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            reverse(&buffer[j], &buffer[i-1]);
            j = i + 1;
        } else {
            buffer[i] = str[i];
        }
    }

    reverse(&buffer[j], &buffer[i-1]);
    printf("Reversed string: %s", buffer);

    return 0;
}

