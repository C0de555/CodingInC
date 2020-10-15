#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters, words, sentences;
    letters = sentences = 0;
    words = 1;


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters ++;
        }
        else if (text[i] == ' ')
        {
            words ++;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences ++;
        }
    }

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
