#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// the points to each letter
int POINT[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_score(string word);

int main(void)
{
    // prompting the user
    string first_word = get_string("Player 1: \n");
    string second_word = get_string("Player 2: \n");

    // the score for the players
    int first_score = calculate_score(first_word);
    int second_score = calculate_score(second_word);

    // displaying the result
    if (first_score > second_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (first_score < second_score)
    {
        printf("Player 2 wins!\n");
    }
    else if ( first_score == second_score)
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += POINT[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINT[word[i] - 'a'];
        }
        else if (! isalpha(word[i]))
        {
            score += 0;
        }
    }
    return score;
}
