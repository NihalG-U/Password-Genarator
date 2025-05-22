

//password Genarator


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

int main() {
    int length, i;
    char password[MAX_LENGTH];

    // Seed the random number generator
    srand(time(0));

    printf("Enter the desired password length: ");
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH) {
        printf("Invalid length. Please enter a value between 1 and %d.\n", MAX_LENGTH);
        return 1;
    }

    // Character sets
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    // Combine all into one character set
    char allChars[200]; // Sufficiently large
    strcpy(allChars, lower);
    strcat(allChars, upper);
    strcat(allChars, digits);
    strcat(allChars, symbols);

    int totalChars = strlen(allChars);

    for (i = 0; i < length; i++) {
        password[i] = allChars[rand() % totalChars];
    }

    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);

    return 0;
}


