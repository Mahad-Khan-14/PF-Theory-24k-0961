#include <stdio.h>
#include <stdlib.h>

void collectRatings(int **scores, int employeeCount, int periodCount);
void showRatings(int **scores, int employeeCount, int periodCount);
int topEmployee(int **scores, int employeeCount, int periodCount);
int bestEvaluationPeriod(int **scores, int employeeCount, int periodCount);
int lowestEmployee(int **scores, int employeeCount, int periodCount);

int main()
{
    int employeeCount, periodCount;

    printf("Enter the number of employees: ");
    scanf("%d", &employeeCount);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &periodCount);

    // Dynamic memory allocation
    int **scores = (int **)malloc(employeeCount * sizeof(int *));
    for (int i = 0; i < employeeCount; i++)
    {
        scores[i] = (int *)malloc(periodCount * sizeof(int));
    }

    // Collect and display ratings
    collectRatings(scores, employeeCount, periodCount);
    showRatings(scores, employeeCount, periodCount);

    // Determine performance results
    printf("\nTop Employee: Employee %d\n", topEmployee(scores, employeeCount, periodCount) + 1);
    printf("Best Evaluation Period: Period %d\n", bestEvaluationPeriod(scores, employeeCount, periodCount) + 1);
    printf("Lowest Performing Employee: Employee %d\n", lowestEmployee(scores, employeeCount, periodCount) + 1);

    for (int i = 0; i < employeeCount; i++)
    {
        free(scores[i]);
    }
    free(scores);

    return 0;
}

void collectRatings(int **scores, int employeeCount, int periodCount)
{
    for (int i = 0; i < employeeCount; i++)
    {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < periodCount; j++)
        {
            do
            {
                printf("  Period %d: ", j + 1);
                scanf("%d", &scores[i][j]);
                if (scores[i][j] < 1 || scores[i][j] > 10)
                {
                    printf("    Invalid rating! Please enter a value between 1 and 10.\n");
                }
            } while (scores[i][j] < 1 || scores[i][j] > 10);
        }
    }
}

void showRatings(int **scores, int employeeCount, int periodCount)
{
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < periodCount; j++)
        {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
}

int topEmployee(int **scores, int employeeCount, int periodCount)
{
    int bestIndex = 0;
    double highestAvg = 0;

    for (int i = 0; i < employeeCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < periodCount; j++)
        {
            sum += scores[i][j];
        }
        double avg = (double)sum / periodCount;
        if (avg > highestAvg)
        {
            highestAvg = avg;
            bestIndex = i;
        }
    }
    return bestIndex;
}

int bestEvaluationPeriod(int **scores, int employeeCount, int periodCount)
{
    int bestPeriod = 0;
    double highestAvg = 0;

    for (int j = 0; j < periodCount; j++)
    {
        int sum = 0;
        for (int i = 0; i < employeeCount; i++)
        {
            sum += scores[i][j];
        }
        double avg = (double)sum / employeeCount;
        if (avg > highestAvg)
        {
            highestAvg = avg;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int lowestEmployee(int **scores, int employeeCount, int periodCount)
{
    int worstIndex = 0;
    double lowestAvg = 10;

    for (int i = 0; i < employeeCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < periodCount; j++)
        {
            sum += scores[i][j];
        }
        double avg = (double)sum / periodCount;
        if (avg < lowestAvg)
        {
            lowestAvg = avg;
            worstIndex = i;
        }
    }
    return worstIndex;
}