#include <stdio.h>

int match(int n)
{
    if (n % 5 == 0)
    {
        return -1;
    }
    else
    {
        return n % 5;
    }
}

int main()
{
    int n;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &n);

    int result = match(n);

    if (result == -1)
    {
        printf("It is impossible for A to guarantee a win. Return -1.\n");
    }
    else
    {
        printf("To guarantee a win, A should pick %d matchstick(s) on the first turn.\n", result);
    }

    return 0;
}
