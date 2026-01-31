#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototype functions
int letter_counter(string text);
int word_counter(string text);
int sentence_counter(string text);

int main(void)
{
    string text = get_string("Text: ");

    // the calculation on text
    int letters = letter_counter(text);
    int words = word_counter(text);
    int sentences = sentence_counter(text);

    // L is the average number of letters per 100 words in the text
    float l = ((float) letters / (float) words) * 100;
    // S is the average number of sentences per 100 words in the text.
    float s = ((float) sentences / (float) words) * 100;

    // Compute the Coleman-Liau index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    if(grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    } else if (grade > 16 )
    {
        printf("Grade 16+\n");
    } else if (grade <1)
    {
        printf("Before Grade 1\n");
    }


}

// counting letters in text
int letter_counter(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// counting words in text
int word_counter(string text)
{
    // start counting at 1, first word befor first space
    int words = 1;
    for (int i = 0, n = strlen(text); i<=n; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return words;
}

// counting sentences in text
int sentence_counter(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i<=n; i++)
    {
        //sentence . ! ?
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
