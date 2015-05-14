#include <stdio.h>

int main(void)
{
    int ascii;

    printf("Enter a ascii code: \n");
    scanf("%d", &ascii);
    printf("%c is the character for acsii code %d.\n", ascii, ascii);

    return 0;
}