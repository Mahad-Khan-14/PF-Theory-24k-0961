// M.Mahad Khan
// 24K-0961
// BCS-1C
// Problem-1

#include <stdio.h>
int main()
{
    int arr[5], small, small2, i;

    printf("Enter 5 elements (n<9999):\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] >= 9999)
        {
            printf("(Value out of range!). Enter a number less than 9999: ");
            return 1;
        }
    }

    small = small2 = 9999;
    for (i = 0; i < 5; i++)
    {
        if (arr[i] < small)
        {
            small2 = small;
            small = arr[i];
        }
        else if (arr[i] < small2 && arr[i] != small)
        {
            small2 = arr[i];
        }
    }
    if (small2 == 9999)
    {
        printf("\nThere is no second smallest element (all elements are equal).\n");
    }
    else
    {
        printf("\nThe Second smallest element in the array is: %d\n", small2);
    }

    printf("\n");

    return 0;
}
