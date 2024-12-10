#include <stdio.h>
#include <string.h>

struct Date
{
    int day, month, year;
};

struct Employee
{
    int employeeID;
    char name[50];
    struct Date joiningDate;
};

void inputEmployeeDetails(struct Employee employees[], int totalEmployees)
{
    for (int i = 0; i < totalEmployees; i++)
    {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", employees[i].name);

        printf("Employee ID: ");
        scanf("%d", &employees[i].employeeID);

        printf("Date of Joining (dd mm yyyy): ");
        scanf("%d %d %d", &employees[i].joiningDate.day, &employees[i].joiningDate.month, &employees[i].joiningDate.year);

        printf("\n");
    }
}

// Function to calculate and display employees with tenure > 3 years
void displayLongTenureEmployees(struct Employee employees[], int totalEmployees)
{
    struct Date currentDate;
    int longTenureCount = 0;

    printf("Enter the current date (dd mm yyyy): ");
    scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);
    printf("\nEmployees with tenure of more than 3 years:\n");
    printf("===========================================\n");

    for (int i = 0; i < totalEmployees; i++)
    {
        int tenureYears = currentDate.year - employees[i].joiningDate.year;

        if (tenureYears > 3 || (tenureYears == 3 &&
                                (currentDate.month > employees[i].joiningDate.month ||
                                 (currentDate.month == employees[i].joiningDate.month &&
                                  currentDate.day >= employees[i].joiningDate.day))))
        {

            printf("Name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Date of Joining: %02d-%02d-%04d\n\n",
                   employees[i].joiningDate.day, employees[i].joiningDate.month, employees[i].joiningDate.year);
            longTenureCount++;
        }
    }

    if (longTenureCount == 0)
    {
        printf("No employees found with tenure greater than 3 years.\n");
    }
    else
    {
        printf("Total Employees with tenure > 3 years: %d\n", longTenureCount);
    }
}

int main()
{
    const int totalEmployees = 4;
    struct Employee employees[totalEmployees];

    inputEmployeeDetails(employees, totalEmployees);
    displayLongTenureEmployees(employees, totalEmployees);

    return 0;
}
