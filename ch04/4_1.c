#include <stdio.h>

int main(void)
{
    char firstname[20], lastname[20];

    printf("Enter your last name:\n");
    scanf("%s", lastname);
    printf("And your first name: \n");
    scanf("%s", firstname);

    printf("%s, %s\n", lastname, firstname);

    return 0;
}