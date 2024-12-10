#include <stdio.h>
#include <string.h>

struct Player
{
    int ballScores[12];
    char playerName[20];
    int totalScore;
};

// Function to input scores
void playGame(struct Player *player)
{
    for (int i = 0; i < 12; i++)
    {
        printf("Enter score for ball %d (0-6): ", i + 1);
        scanf("%d", &player->ballScores[i]);
    }
}

// Function to validate scores
void validateScores(struct Player *player)
{
    player->totalScore = 0; // Reset score before calculation

    for (int i = 0; i < 12; i++)
    {
        if (player->ballScores[i] < 0 || player->ballScores[i] > 6)
        {
            printf("Invalid score for ball %d. Set to 0.\n", i + 1);
            player->ballScores[i] = 0;
        }
        player->totalScore += player->ballScores[i];
    }
}

// Function to determine the winner
void findWinner(struct Player player1, struct Player player2)
{
    printf("\n====== Match Result ======\n");

    if (player1.totalScore > player2.totalScore)
    {
        printf("Winner: %s\n", player1.playerName);
    }
    else if (player2.totalScore > player1.totalScore)
    {
        printf("Winner: %s\n", player2.playerName);
    }
    else
    {
        printf("It's a Draw!\n");
    }
}

// Function to display the match scoreboard
void displayScoreboard(struct Player player1, struct Player player2)
{
    printf("\n====== Match Scoreboard ======\n\n");

    // Display Player 1 Details
    printf("Player: %s\n", player1.playerName);
    printf("Ball Scores: [");
    for (int i = 0; i < 12; i++)
    {
        printf("%d", player1.ballScores[i]);
        if (i < 11)
            printf(", ");
    }
    printf("]\n");
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n\n", player1.totalScore / 12.0);

    // Display Player 2 Details
    printf("Player: %s\n", player2.playerName);
    printf("Ball Scores: [");
    for (int i = 0; i < 12; i++)
    {
        printf("%d", player2.ballScores[i]);
        if (i < 11)
            printf(", ");
    }
    printf("]\n");
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n\n", player2.totalScore / 12.0);
}

// Main function
int main()
{
    struct Player player1, player2;

    printf("Enter Player 1 Name: ");
    scanf(" %[^\n]s", player1.playerName);

    printf("Enter Player 2 Name: ");
    scanf(" %[^\n]s", player2.playerName);

    printf("\n=== Scores for %s ===\n", player1.playerName);
    playGame(&player1);

    printf("\n=== Scores for %s ===\n", player2.playerName);
    playGame(&player2);

    validateScores(&player1);
    validateScores(&player2);

    findWinner(player1, player2);
    displayScoreboard(player1, player2);

    return 0;
}
