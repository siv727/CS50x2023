#include <stdio.h>
#include <ctype.h>
#include <string.h>

int word_val(char player[], int *size);
void remove_char(char player[], int index, int *size);
int letter_value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main()
{
    char p1_word[50];
    char p2_word[50];

    printf("Player 1: ");
    fgets(p1_word, 50, stdin);

    printf("Player 2: ");
    fgets(p2_word, 50, stdin);

    int len_p1 = strlen(p1_word);
    int len_p2 = strlen(p2_word);

    int p1_result = word_val(p1_word, &len_p1);
    int p2_result = word_val(p2_word, &len_p2);

    if (p1_result > p2_result)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_result < p2_result)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int word_val(char player[], int *size)
{
    int total = 0;
    for (int i = 0; i < *size; i++)
    {
        if (!(isalpha(player[i])))
        {
            remove_char(player, i, size);
            break;
        }
        if (islower(player[i]))
        {
            player[i] -= 32;
        }
        total += letter_value[player[i] - 'A'];
    }
    return total;
}

void remove_char(char player[], int index, int *size)
{
    for (int i = index; i < *size - 1; i++)
    {
        player[i] = player[i + 1];
    }
    (*size)--;
}
