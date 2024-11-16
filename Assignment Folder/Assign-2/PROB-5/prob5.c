#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numValues, maxValue = 0;
    int values[MAX_SIZE];

    printf("Enter the number of values (max %d): ", MAX_SIZE);
    scanf("%d", &numValues);

    if (numValues > MAX_SIZE)
    {
        printf("Error: Number of values exceeds the maximum limit of %d.\n", MAX_SIZE);
        return 1;
    }

    for (int i = 0; i < numValues; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
        if (values[i] > maxValue)
            maxValue = values[i];
    }

    printf("\nHorizontal Histogram:\n");
    for (int i = 0; i < numValues; i++)
    {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\nVertical Histogram:\n");
    for (int i = maxValue; i > 0; i--)
    {
        for (int j = 0; j < numValues; j++)
        {
            if (values[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    for (int i = 0; i < numValues; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}
