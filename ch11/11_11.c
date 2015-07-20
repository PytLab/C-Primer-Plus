#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 81

void statistic(char *);

int main(void)
{
    char ch;
    char input[MAXSIZE];
    int ct = 0; /*输入计数*/

    puts("Enter something(CTRL+Z to stop): ");
    /*输入字符*/
    while(ct < MAXSIZE-1 && (ch = getchar()) != EOF)
    {
        input[ct] = ch;
        ct++;
    }
    input[ct] = '\0';

    statistic(input);

    return 0;
}

void statistic(char * string)
{
    char ch;
    int supper = 0, space = 0, word = 0, lower = 0, punct = 0, digit = 0;
    int ct = 0; /*计数*/

    while(ch = *string)
    {
        if(isspace(ch))
            space++;
        /*前一个字符为空白或者是第一个非空白字符，则可以认为是一个单词开始*/
        else
        {
            if(isspace(*(string-1)) || ct == 0)
                word++;
            if(isupper(ch))
                supper++;
            else if(islower(ch))
                lower++;
            else if(ispunct(ch))
                punct++;
            else if(isdigit(ch))
                digit++;
        }

        ct++;
        string++;
    }

    printf("supper: %d\n", supper);
    printf(" space: %d\n", space);
    printf("  word: %d\n", word);
    printf(" lower: %d\n", lower);
    printf(" punct: %d\n", punct);
    printf(" digit: %d\n", digit);
}
