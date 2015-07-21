#include <stdio.h>

void critic(int *);

int main(void)
{
    int units;

    puts("How many pounds to a firkin of butter?");
    scanf("%d", &units);
    while(units != 56)
        critic(&units);
    puts("You must have looked it up!");

    return 0;
}

void critic(int * pt)
{
    puts("No luck, chumy. Try again!");
    scanf("%d", pt);
}
