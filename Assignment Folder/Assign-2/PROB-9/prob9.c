// M.Mahad Khan
// 24K-0961
// BCS-1C
// Problem 9

#include <stdio.h>

void upDown(char grid[][5], int *playerRow, int *playerCol, int *newRow, int *itemsCollected);
void leftRight(char grid[][5], int *playerRow, int *playerCol, int *newCol, int *itemsCollected);
void printGrid(char grid[5][5]);

int main()
{
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}};

    printf("Welcome to the Grid Adventure Game!\n\n");
    printf("Enter the following keys to play:\n");
    printf("W: Up\nS: Down\nA: Left\nD: Right\nQ: Quit\n\n");
    printf("Let's Start!\n");

    int playerRow = 4, playerCol = 4;
    int itemsCollected = 0;
    char input;

    while (1)
    {
        printGrid(grid);
        printf("\nCollected Items: %d\n", itemsCollected);
        printf("Enter your move (W/A/S/D/Q): ");
        scanf(" %c", &input);

        if (input >= 'a' && input <= 'z')
        {
            input -= 32;
        }

        int newRow = playerRow;
        int newCol = playerCol;

        if (input == 'W')
        {
            newRow = playerRow - 1;
            upDown(grid, &playerCol, &playerRow, &newRow, &itemsCollected);
        }
        else if (input == 'S')
        {
            newRow = playerRow + 1;
            upDown(grid, &playerCol, &playerRow, &newRow, &itemsCollected);
        }
        else if (input == 'A')
        {
            newCol = playerCol - 1;
            leftRight(grid, &playerRow, &playerCol, &newCol, &itemsCollected);
        }
        else if (input == 'D')
        {
            newCol = playerCol + 1;
            leftRight(grid, &playerRow, &playerCol, &newCol, &itemsCollected);
        }
        else if (input == 'Q')
        {
            printf("\nGame Over! You collected %d item(s).\n", itemsCollected);
            break;
        }
        else
        {
            printf("Invalid input! Please enter W, A, S, D, or Q.\n");
        }
    }

    return 0;
}

void printGrid(char grid[5][5])
{
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %c |", grid[i][j]);
        }
        printf("\n");
    }
}

void upDown(char grid[][5], int *playerCol, int *playerRow, int *newRow, int *itemsCollected)
{
    if (*newRow >= 0 && *newRow < 5)
    {
        if (grid[*newRow][*playerCol] == ' ')
        {

            grid[*playerRow][*playerCol] = ' ';
            grid[*newRow][*playerCol] = 'P';
            *playerRow = *newRow;
        }
        else if (grid[*newRow][*playerCol] == 'I')
        {

            (*itemsCollected)++;
            grid[*playerRow][*playerCol] = ' ';
            grid[*newRow][*playerCol] = 'P';
            *playerRow = *newRow;
        }
        else if (grid[*newRow][*playerCol] == 'X')
        {
            printf("You cannot move into an obstacle!\n");
        }
    }
    else
    {
        printf("Invalid move! You are at the edge of the grid.\n");
    }
}

void leftRight(char grid[][5], int *playerRow, int *playerCol, int *newCol, int *itemsCollected)
{
    if (*newCol >= 0 && *newCol < 5)
    {
        if (grid[*playerRow][*newCol] == ' ')
        {

            grid[*playerRow][*playerCol] = ' ';
            grid[*playerRow][*newCol] = 'P';
            *playerCol = *newCol;
        }
        else if (grid[*playerRow][*newCol] == 'I')
        {

            (*itemsCollected)++;
            grid[*playerRow][*playerCol] = ' ';
            grid[*playerRow][*newCol] = 'P';
            *playerCol = *newCol;
        }
        else if (grid[*playerRow][*newCol] == 'X')
        {
            printf("You cannot move into an obstacle!\n");
        }
    }
    else
    {
        printf("Invalid move! You are at the edge of the grid.\n");
    }
}
