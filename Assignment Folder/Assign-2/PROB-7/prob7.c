// M.Mahad Khan
// 24K-0961
// BCS-1C
// Problem-7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to fill the array with random characters and last row with ID
void fill(char arr[6][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = 'A' + (rand() % 26); // Random alphabets
        }
    }
    arr[5][0] = '0';
    arr[5][1] = '9';
    arr[5][2] = '6';
    arr[5][3] = '1';
    for (int j = 4; j < 5; j++)
    {
        arr[5][j] = 'A' + (rand() % 26);
    }
}

void disparr(char arr[6][5])
{
    printf("\nCharacter Array:\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int search(char arr[6][5], const char *str)
{
    int len = strlen(str);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= 5 - len; j++)
        {
            if (strncmp(&arr[i][j], str, len) == 0)
            {
                return 1;
            }
        }
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i <= 6 - len; i++)
        {
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (arr[i + k][j] != str[k])
                {
                    found = 0;
                    break;
                }
            }
            if (found)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    char characters[6][5];
    char input[100];
    int score = 0;

    srand(time(NULL));

    while (1)
    {
        fill(characters);
        disparr(characters);

        while (1)
        {
            printf("Enter a string to search (or type 'END' to repopulate): ");
            scanf("%s", input);

            if (strcmp(input, "END") == 0)
            {
                break;
            }

            if (search(characters, input))
            {
                score++;
                printf("%s is present. Score: %d\n", input, score);
            }
            else
            {
                score--;
                printf("%s is not present. Score: %d\n", input, score);
            }
        }
    }

    return 0;
}
