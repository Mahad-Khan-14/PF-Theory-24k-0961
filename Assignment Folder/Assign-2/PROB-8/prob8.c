// M.Mahad Khan
// 24K-0961
// BCS-1C
// Problem-8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HEX_LENGTH 20

int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);

int isValidBinary(int number);
int isValidHexadecimal(const char *hexNumber);

int displayMenu()
{
    int choice;

    printf("\n===========================\n");
    printf("Numerical Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    printf("===========================\n");
    printf("Enter your choice: ");

    while (scanf("%d", &choice) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        while (getchar() != '\n')
            ;

        printf("Enter your choice: ");
    }

    return choice;
}

int main()
{
    int choice, decimalNumber, binaryNumber;
    char hexNumber[MAX_HEX_LENGTH];

    while (1)
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &binaryNumber);
            int decimalResult = BinaryToDecimal(binaryNumber);
            if (decimalResult != -1)
            {
                printf("Decimal equivalent: %d\n", decimalResult);
            }
            break;

        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            if (decimalNumber < 0)
            {
                printf("Negative numbers are not supported!\n");
            }
            else
            {
                printf("Binary equivalent: %d\n", DecimalToBinary(decimalNumber));
            }
            break;

        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            if (decimalNumber < 0)
            {
                printf("Negative numbers are not supported!\n");
            }
            else
            {
                DecimalToHexadecimal(decimalNumber);
            }
            break;

        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNumber);
            HexadecimalToDecimal(hexNumber);
            break;

        case 5:
            printf("Enter a binary number: ");
            scanf("%d", &binaryNumber);
            if (isValidBinary(binaryNumber))
            {
                BinaryToHexadecimal(binaryNumber);
            }
            else
            {
                printf("Invalid binary number!\n");
            }
            break;

        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNumber);
            HexadecimalToBinary(hexNumber);
            break;

        case 7:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

int isValidBinary(int number)
{
    while (number > 0)
    {
        if (number % 10 > 1)
        {
            return 0;
        }
        number /= 10;
    }
    return 1;
}

int isValidHexadecimal(const char *hexNumber)
{
    for (int i = 0; i < strlen(hexNumber); i++)
    {
        if (!((hexNumber[i] >= '0' && hexNumber[i] <= '9') ||
              (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') ||
              (hexNumber[i] >= 'a' && hexNumber[i] <= 'f')))
        {
            return 0;
        }
    }
    return 1;
}

int BinaryToDecimal(int number)
{
    if (!isValidBinary(number))
    {
        printf("Invalid binary number!\n");
        return -1;
    }

    int decimal = 0, base = 1, remainder;
    while (number > 0)
    {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int DecimalToBinary(int number)
{
    int binary = 0, base = 1;

    while (number > 0)
    {
        int lastDigit = number % 2;
        binary += lastDigit * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number)
{
    char hex[20];
    int i = 0;

    if (number == 0)
    {
        printf("Hexadecimal equivalent: 0\n");
        return;
    }

    while (number != 0)
    {
        int temp = number % 16;

        if (temp < 10)
            hex[i++] = temp + '0';
        else
            hex[i++] = temp - 10 + 'A';

        number /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--)
    {
        putchar(hex[j]);
    }
    putchar('\n');
}

void HexadecimalToDecimal(char hexNumber[])
{
    if (!isValidHexadecimal(hexNumber))
    {
        printf("Invalid hexadecimal number!\n");
        return;
    }
    int decimal = (int)strtol(hexNumber, NULL, 16);
    printf("Decimal equivalent: %d\n", decimal);
}

void BinaryToHexadecimal(int number)
{
    int decimal = BinaryToDecimal(number);
    if (decimal != -1)
    {
        DecimalToHexadecimal(decimal);
    }
}

void HexadecimalToBinary(char hexNumber[])
{
    if (!isValidHexadecimal(hexNumber))
    {
        printf("Invalid hexadecimal number!\n");
        return;
    }

    int decimal = (int)strtol(hexNumber, NULL, 16);
    if (decimal == 0)
    {
        printf("Binary equivalent: 0\n");
        return;
    }

    char binary[32];
    int index = 0;

    while (decimal > 0)
    {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    printf("Binary equivalent: ");
    for (int j = index - 1; j >= 0; j--)
    {
        putchar(binary[j]);
    }
    putchar('\n');
}
