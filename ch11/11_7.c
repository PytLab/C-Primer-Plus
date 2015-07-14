#include <stdio.h>
#include <string.h>

int main(void)
{
    char longstr[21];
    char shortstr[11];
    char * res;

    char * string_in(char *, char *);

    puts("Enter long string(QUIT to quit): ");
    gets(longstr);
    puts("Enter short string: ");
    gets(shortstr);

    do
    {
        res = string_in(longstr, shortstr);
        if(res)
            printf("%s is in %s, index: %p, first_char: %c\n", shortstr, longstr, res, *res);
        else
            printf("%s is not in %s\n", shortstr, longstr);
        puts("Enter another long string: ");
        gets(longstr);
        puts("Enter another short string: ");
        gets(shortstr);
    }while(strcmp(longstr, "QUIT") && strcmp(longstr, "QUIT"));

    return 0;
}

char * string_in(char * longstr, char * shortstr)
{
    int i, j, sub_i;  // longstr和shortstr的索引, sub_i为longstr子循环的索引
    char firstch = shortstr[0];
    int in = 0;

    for(i = 0; longstr[i] != '\0'; i++)
    {
        if(longstr[i] == firstch)
        {
            for(j = 1, sub_i = i+1; shortstr[j] != '\0'; j++, sub_i++)
            {
                if(shortstr[j] == longstr[sub_i])
                {
                    in = 1;
                    continue;
                }
                else
                {
                    in = 0;
                    break;
                }
            }
            if(in) return longstr + i;  // 返回第一个字符的指针
        }
    }
    /*如果主循环结束还是没有，返回NULL*/
    return NULL;
}
