// M.Mahad Khan
// 24k-0961
// BCS-1C
// Problem-10

#include <stdio.h>

/*
 * This program generates a star pattern for a given odd input value `N`.
 * The pattern has a central line of stars, with symmetrical upper and lower parts.
 * Only odd values of `N` are accepted, and the output adjusts proportionally for large values.
 */

void printGrid(int N);

int main()
{
    int N;

    // Prompt the user for an odd number
    printf("Enter an odd number for N: ");
    scanf("%d", &N);

    // Validate the input
    if (N % 2 == 0)
    {
        printf("Error: Only odd numbers are allowed.\n");
        return 1;
    }

    // Generate the star pattern
    printGrid(N);

    return 0;
}

/*
 * Function: printGrid;

 * Generates and prints the star pattern for the given odd value of `N`.
 *
 * Parameters:
 *   N - The odd integer defining the size of the star pattern.
 */

void printGrid(int N)
{
    int space, innerSpace, star, i, j;

    // Initialize spaces
    space = (N * 2) - 2; // Outer spaces
    innerSpace = 0;      // Inner spaces for the top part

    // Top part of the pattern
    for (i = 0; i < N - 1; i++)
    {
        // Outer spaces
        for (j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("*"); // First star in the row

        // Inner spaces
        for (j = 0; j < innerSpace; j++)
        {
            printf(" ");
        }
        if (i > 0)
        {
            printf("*"); // Second star if not the first row
        }

        printf("\n");

        space--;                        // Reduce outer spaces
        innerSpace += (i == 0) ? 1 : 2; // Increment inner spaces
    }

    // Middle row
    for (i = 0; i < N; i++)
    {
        printf("*");
    }
    for (i = 0; i < innerSpace; i++)
    {
        printf(" ");
    }
    for (i = 0; i < N; i++)
    {
        printf("*");
    }
    printf("\n");

    // Bottom part of the pattern
    innerSpace = (innerSpace * 2) - 1; // Adjust inner space for the bottom part
    space = 1;                         // Reset outer space

    for (i = 0; i < N - 1; i++)
    {
        // Outer spaces
        for (j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("*"); // First star

        // Inner spaces
        for (j = 0; j < innerSpace; j++)
        {
            printf(" ");
        }
        printf("*"); // Second star
        printf("\n");

        innerSpace -= 2; // Reduce inner spaces
        space++;         // Increment outer spaces
    }

    // Lower corners
    space = N - 2;  // Adjust spaces for the last few rows
    innerSpace = 1; // Reset inner space
    for (i = 0; i < N - 2; i++)
    {
        // Left spaces
        for (j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("*");

        // Left inner spaces
        for (j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("*");

        // Right inner spaces
        for (j = 0; j < innerSpace; j++)
        {
            printf(" ");
        }
        printf("*");

        // Right spaces
        for (j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");

        space--;         // Decrement spaces
        innerSpace += 4; // Increase inner spaces
    }

    // Final bottom row
    innerSpace += 2;
    printf("*");
    for (j = 0; j < innerSpace; j++)
    {
        printf(" ");
    }
    printf("*");
    printf("\n");
}
