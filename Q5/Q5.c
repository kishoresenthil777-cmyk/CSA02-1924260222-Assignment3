
#include <stdio.h>
#include <ctype.h>

// TODO 1: Count words without using string.h
int word_count(const char s[])
{
    int count = 0, inside = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && inside == 0) {
            count++;
            inside = 1;
        }
        else if (s[i] == ' ') {
            inside = 0;
        }
    }

    return count;
}

// TODO 2: Check palindrome ignoring case and non-letters
int is_palindrome(const char s[])
{
    int left = 0, right = 0;

    while (s[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {

        while (left < right && !isalpha((unsigned char)s[left])) {
            left++;
        }

        while (left < right && !isalpha((unsigned char)s[right])) {
            right--;
        }

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right])) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

// Convert string to uppercase
void to_uppercase(char s[])
{
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
}

// Reverse string without string.h
void reverse_string(char s[])
{
    int left = 0, right = 0;
    char temp;

    while (s[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main(void)
{
    char message[] = "Meet at the library at 5 PM";
    char upper[] = "hello college";
    char reverse[] = "PROGRAM";
    
    printf("Words: %d\n", word_count(message));

    printf("Palindrome: %d\n",
           is_palindrome("Madam, I'm Adam"));

    printf("Not Palindrome: %d\n",
           is_palindrome("Hello"));

    to_uppercase(upper);
    printf("Uppercase: %s\n", upper);

    reverse_string(reverse);
    printf("Reversed: %s\n", reverse);

    printf("Empty string words: %d\n", word_count(""));

    printf("Tab test: %d\n", word_count("Hello\tWorld"));

    return 0;
}
