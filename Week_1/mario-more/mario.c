#include <stdio.h>

int main(void)
{
    int height, valid;
    do
    {
        printf("Height: ");
        valid = scanf("%d", &height);
        // Added condition to catch string input error (09/15/2024)
        if (valid != 1)
            while (getchar() != '\n')
                ;
    } while (valid != 1 || height <= 0 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}