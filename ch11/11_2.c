#include <stdio.h>

void input(char *, int);

int main(void)
{
    char string[81];
    int n;

    puts("Enter the char number: ");
    scanf("%d", &n);
    getchar();  // 滤去回车(换行符)
    printf("Enter %d charactors: \n", n);
    input(string, n);
    puts(string);

    return 0;
}

void input(char * string, int n)
{
    int i;
    char ch;
    for(i = 0; i < n; i++)
    {
        string[i] = getchar();
        if(string[i] == '\n' || string[i] == '\t' || string[i] == ' ')
            break;
    }
    string[i+1] = '\0';
}
