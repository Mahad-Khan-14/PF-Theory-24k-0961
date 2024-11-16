#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int reduceDuplicates(const char *input, char *output)
{
    int duplicatesCount = 0;
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (i == 0 || input[i] != input[i - 1])
        {
            output[j++] = input[i];
        }
        else
        {
            duplicatesCount++;
        }
    }

    output[j] = '\0';
    return duplicatesCount;
}

int main()
{
    char original[MAX_INPUT_LENGTH];
    char minimized[MAX_INPUT_LENGTH];

    printf("Enter a string (up to %d characters): ", MAX_INPUT_LENGTH - 1);
    scanf("%99s", original);

    int totalRemoved = reduceDuplicates(original, minimized);

    printf("Optimized string: %s\n", minimized);
    printf("Characters removed: %d\n", totalRemoved);

    return 0;
}
