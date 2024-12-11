// M.Mahad Khan
// 24K-0961
// BCS-1C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate email address
int validateEmail(char *email)
{
    if (email == NULL || strlen(email) == 0)
    {
        printf("Error: Email cannot be empty.\n");
        return 0;
    }

    char *atSymbol = strchr(email, '@');
    if (!atSymbol || atSymbol == email)
    {
        printf("Error: Missing or incorrectly placed '@'.\n");
        return 0;
    }

    char *dotSymbol = strchr(atSymbol, '.');
    if (!dotSymbol || dotSymbol == atSymbol + 1)
    {
        printf("Error: Missing '.' after '@' or placed incorrectly.\n");
        return 0;
    }

    if (*(dotSymbol + 1) == '\0')
    {
        printf("Error: Email cannot end with a dot.\n");
        return 0;
    }

    return 1; // Email is valid
}

int main()
{
    // Allocate memory for email input
    char *email = malloc(100 * sizeof(char));
    if (!email)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter your email: ");
    if (fgets(email, 100, stdin) != NULL)
    {

        email[strcspn(email, "\n")] = '\0';

        // Validate email
        if (validateEmail(email))
        {
            printf("Valid Email\n");
        }
        else
        {
            printf("Invalid Email\n");
        }
    }
    else
    {
        printf("Error reading input.\n");
    }

    free(email);
    return 0;
}
