#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool
is_palindrome(const char *string)
{
    size_t string_length, i;

    string_length = strlen(string) - 1;

    for(i = 0; i < string_length; i++) {
        if(string[i] != string[string_length - i -1]) {
            return false;
        }
    }

    return true;
}


int
main(void)
{
    char string[99];

    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);

    if(is_palindrome(string)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}