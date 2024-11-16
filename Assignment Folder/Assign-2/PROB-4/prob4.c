#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char arr[n][100];
    char sorted[n][100];
    int processed[n];
    memset(processed, 0, sizeof(processed));

    for (int i = 0; i < n; i++)
    {
        printf("Enter word %d: ", i + 1);
        scanf("%s", arr[i]);
        strcpy(sorted[i], arr[i]);
        sortString(sorted[i]);
    }

    printf("Grouped Anagrams: [");
    for (int i = 0; i < n; i++)
    {
        if (!processed[i])
        {
            printf("[\"%s\"", arr[i]);
            processed[i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (!processed[j] && strcmp(sorted[i], sorted[j]) == 0)
                {
                    printf(", \"%s\"", arr[j]);
                    processed[j] = 1;
                }
            }
            printf("]");
            if (i < n - 1)
            {
                printf(", ");
            }
        }
    }
    printf("]\n");

    return 0;
}
