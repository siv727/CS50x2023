#include <stdio.h>

int main(void)
{
    char name[150];
    printf("What's your name? ");
    scanf("%[^\n]s", name);

    printf("hello, %s\n", name);

    return 0;
}