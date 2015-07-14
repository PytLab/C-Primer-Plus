#include <stdio.h>

int main()
{
    char ch;
    char * string = "shaozhengjiang";
    char * res;
    char * strch(char *, char);

    puts("Enter the charactor you want(CTRL+Z to quit): ");
    ch = getchar();
    getchar();  //滤去换行符
    while(ch != EOF)
    {
        res = strch(string, ch);
        if(res)
            printf("The address of %c is %p\n", ch, res);
        else
            printf("%c is not in %s\n", ch, string);
        puts("Enter another charactor you want(CTRL+Z to quit): ");
        ch = getchar();
        getchar();  //滤去换行符
    }
    
    return 0;
}

char * strch(char * string, char target)
{
    char ch = string[0];
    int i = 0;

    while(ch != '\0')
    {
        if(ch == target)
            return string + i;
        else
            ch = string[++i];
    }
    
    return NULL;
}