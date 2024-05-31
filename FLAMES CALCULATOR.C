#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count common characters
int countCommonCharacters(char name1[], char name2[]) {
    int count = 0;
    int char_count[256] = {0};

    // Convert both names to lowercase and count occurrences of each character in name1
    for (int i = 0; name1[i]; i++) {
        char_count[tolower(name1[i])]++;
    }

    // For each character in name2, check if it is in name1
    for (int i = 0; name2[i]; i++) {
        if (char_count[tolower(name2[i])] > 0) {
            char_count[tolower(name2[i])]--;
            count++;
        }
    }

    return count;
}

// Function to get FLAMES result
char getFLAMESResult(int count) {
    char flames[] = "FLAMES";
    int length = strlen(flames);
    int index = 0;

    // Reduce the length of the array until only one character is left
    for (int i = length; i > 1; i--) {
        index = (index + count - 1) % i;
        for (int j = index; j < i - 1; j++) {
            flames[j] = flames[j + 1];
        }
    }

    return flames[0];
}

int main() {
    char name1[100], name2[100];
    int commonChars;

    printf("Enter the first name: ");
    scanf("%s", name1);
    printf("Enter the second name: ");
    scanf("%s", name2);

    commonChars = countCommonCharacters(name1, name2);

    int totalChars = strlen(name1) + strlen(name2) - 2 * commonChars;

    char result = getFLAMESResult(totalChars);

    switch(result) {
        case 'F':
            printf("Friend\n");
            break;
        case 'L':
            printf("Lover\n");
            break;
        case 'A':
            printf("Affection\n");
            break;
        case 'M':
            printf("Marry\n");
            break;
        case 'E':
            printf("Enemy\n");
            break;
        case 'S':
            printf("Siblings\n");
            break;
        default:
            printf("Error\n");
    }

    return 0;
}
