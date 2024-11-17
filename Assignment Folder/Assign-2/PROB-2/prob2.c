// M.Mahad Khan
// 24K-0961
// BCS-1C
// Problem-2

#include <stdio.h>
#include <string.h>

void countCharacterFrequency(char slogans[][50], int sloganIndex);

int main()
{
    int numSlogans;
    printf("Enter the number of slogans: ");
    scanf("%d", &numSlogans);
    getchar();

    char slogans[numSlogans][50];

    for (int i = 0; i < numSlogans; i++)
    {
        printf("Slogan %d: ", i + 1);
        fgets(slogans[i], 50, stdin);
        slogans[i][strcspn(slogans[i], "\n")] = '\0';
    }

    for (int i = 0; i < numSlogans; i++)
    {
        printf("\nFor \"%s\": ", slogans[i]);
        countCharacterFrequency(slogans, i);
    }

    return 0;
}

void countCharacterFrequency(char slogans[][50], int sloganIndex)
{
    int frequency[256] = {0};

    for (int i = 0; slogans[sloganIndex][i] != '\0'; i++)
    {
        frequency[(unsigned char)slogans[sloganIndex][i]]++;
    }

    printf("{");
    int firstPrint = 1;
    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] > 0)
        {
            if (!firstPrint)
                printf(", ");
            printf("'%c': %d", i, frequency[i]);
            firstPrint = 0;
        }
    }
    printf("}\n");
}
