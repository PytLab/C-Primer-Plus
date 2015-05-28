#include <stdio.h>

int main(void)
{
    int guess, upper = 100, lower = 0;
    char ans;

    puts("Pick an integer from 1 to 100. I will try to guess ");
    guess = (upper + lower)/2;
    printf("Uh...is your number %d?\n", guess);
    puts("Is this guess too large or too small? L for large, S for small, Y for yes: ");
    scanf("%c", &ans);

    /*检测输入值的合法性*/
    while(ans != 'L' && ans != 'S' && ans != 'Y')
    {
        puts("L for large, S for small, Y for yes:");  //为毛会输出两次??
        scanf("%c", &ans);
    }

    while(ans != 'Y')
    {
        if(ans == 'L')
            upper = guess;
        else if(ans == 'S')
            lower = guess;

        guess = (lower + upper)/2;
        printf("Uh...is your number %d?\n", guess);
        puts("L for large, S for small, Y for yes: ");
        scanf("%c", &ans);
        while(ans != 'L' && ans != 'S' && ans != 'Y')
        {
            puts("L for large, S for small, Y for yes:");  //为毛会输出两次??
            scanf("%c", &ans);
        }
    }

    printf("Got it! Your number is %d!\n", guess);

    return 0;

}