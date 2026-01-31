#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool all_is_alpha(string key);
bool all_letters_exist (string key);
string encrypt(string key, string text);
int main(int argc, string argv[])
{
    // if more than one argument, or no argument return error
    if (argc > 2 || argc < 2 )
    {
        printf("Enter one argument!\n");
        return 1;
    }
    //if not all chars in the argument are alphabetical, not 26 letter, or not containing each letter exactly once return error
    if (! all_is_alpha(argv[1]) || strlen(argv[1]) != 26 || ! all_letters_exist(argv[1]))
    {
        printf("Enter a valid argument!");
        return 1;
    }
    // all good? prompt the user for input
    string plaintext = get_string("plaintext: ");
    //encrypting the text
    string ciphertext = encrypt(argv[1], plaintext);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
// check if all is alphabetical
bool all_is_alpha(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}
//checks if containing each letter exactly once
bool all_letters_exist (string key)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int test = 0;
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
       for (int j = 0, o = strlen(key); i < n; i++)
       {
           if (alphabet[i] == toupper(key[j]))
           {
            test++;
           }
           if (test > 1)
           {
            return false;
            break;
           }
       }
       test = 0;
    }
    return true;
}
// encrypting the text
string encrypt(string key, string text)
{
    string encrypted = NULL;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            encrypted[i] = key[text[i]-'A'];
        }
        else if (islower(text[i]))
        {
            encrypted[i] = key[text[i]-'a'];
        }
        else
        {
            encrypted[i] = text[i];
        }
    }
    return encrypted;
}
