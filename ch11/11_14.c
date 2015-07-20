#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int atoi(char *);

int main(int argc, char * argv[])
{
    int a, b;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%d*%d = %d\n", a, a, a*b);
    
    return 0;
}

int atoi(char * string)
{
    int len, i = 0;
    char ch;
    int num, res = 0;

    len = strlen(string);
    while((ch = *string) && isdigit(ch))
    {
        num = (int)(ch - '0');
        res += num*pow(10, len-i-1);
        i++;
        string++;
    }

    return res;
}
