#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int readable(char *text, int size);

int main()
{
    int size = 8, len = 0;
    char *text = (char *)malloc(size * sizeof(char));

    printf("Text: ");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (len == size - 1)
        {
            size *= 2;
            text = (char *)realloc(text, size * sizeof(char));
        }
        text[len++] = (char)ch;
    }
    text[len] = '\0';

    int grade = readable(text, len);

    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);

    free(text);
}

int readable(char *text, int size)
{
    double letterCt = 0, sentenceCt = 0, wordCt = 1;
    double index, letter, sentence;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
            wordCt++;
        else if (isalpha(text[i]))
            letterCt++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentenceCt++;
        else
            continue;
    }
    letter = (letterCt / wordCt) * 100;
    sentence = (sentenceCt / wordCt) * 100;
    index = 0.0588 * letter - 0.296 * sentence - 15.8;
    return round(index);
}