#include <stdio.h>
#include <string.h>

#define MAXINP 10 /*最多输入的字符串*/
#define MAXLEN 31 /*字符串的最大长度*/

void strsrt_len(char **, int);
int get_first_word_len(char *);
void strsrt_word_len(char **, int);
void output(char **, int);
void show_stars(int);
void show_menu(void);
void strsrt_init(char **, int);
void inputout(char (*)[MAXLEN], int);

int main(void)
{
    char input[MAXINP][MAXLEN];
    char * pts[MAXINP];
    int in = 0; /*输入计数器*/
    int choice;

    printf("Enter to %d lines with max lenght %d each line: \n", MAXINP, MAXLEN);
    puts("CTRL + Z to stop...");

    while(in < MAXINP && gets(input[in]) != NULL && *input[in] != '\0')
    /*小于字符串个数限制&&不是EOF&&不是空字符串*/
    {
        pts[in] = input[in];
        in++;
    }/*字符串存储完毕*/
    
    show_menu();
    puts("Enter your choice: ");
    scanf("%d", &choice);
    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                puts("initial strings:");
                inputout(input, in);
                break;
            case 2:
                //strsrt_len(pts, in);
                strsrt_init(pts, in);
                puts("Output: ");
                output(pts, in);
                break;
            case 3:
                strsrt_len(pts, in);
                puts("Output: ");
                output(pts, in);
                break;
            case 4:
                strsrt_word_len(pts, in);
                puts("Output: ");
                output(pts, in);
                break;
            default:
                puts("Illegal choice!");
        }

        puts("Enter your choice again: ");
        scanf("%d", &choice);
    }
    puts("Goodbye!");
    return 0;
}

/*********************************************************
Function:    strsrt_init()
Description: 使用选择排序将字符串数组按照ASCII顺序进行排序
Called By:   main()
Input:       char * strings[], 字符指针数组
             int num, 字符指针数组中有效字符串数目
Return:      void, 操作指针数组本身
**********************************************************/
void strsrt_init(char ** strings, int num)
{
    int top, seek; /*分别为外层循环和内层循环计数*/
    char * tmp;    /*交换指针时临时指针变量*/

    for(top = 0; top < num - 1; top++)
    {
        for(seek = top + 1; seek < num; seek++)
        {
            if(*strings[seek] < *strings[top])
            {
                tmp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = tmp;
            }
        } /*结束内层比较循环*/
    } /*结束外层循环*/
}

/*使用选择排序将字符串数组按照字符串长度顺序进行排序*/
void strsrt_len(char ** strings, int num)
{
    int top, seek;
    char * tmp;

    for(top = 0; top < num-1; top++)
    {
        for(seek = top + 1; seek < num; seek++)
        {
            if(strlen(strings[seek]) < strlen(strings[top]))
            {
                tmp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = tmp;
            }
        }
    }
}

/*使用选择排序将字符串数组按照第一个单词的长度顺序进行排序*/
void strsrt_word_len(char ** strings, int num)
{
    int top, seek;
    char * tmp;

    for(top = 0; top < num-1; top++)
    {
        for(seek = top+1; seek < num; seek++)
        {
            if(get_first_word_len(strings[seek])
                    < get_first_word_len(strings[top]))
            {
                tmp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = tmp;
            }
        }
    }
}

/*获取字符串中第一个word的长度*/
int get_first_word_len(char * string)
{
    int len = 0; /*长度计数*/
    
    while(*string != '\0' && *string != ' ')
    {
        string++;
        len++;
    }
    return len;
}

void output(char * strings[], int num)
{
    int ct;

    for(ct = 0; ct < num; ct++)
        puts(strings[ct]);
}

void show_stars(int n)
{
    int i;

    for(i = 0; i < n; i++)
        putchar('*');
    putchar('\n');
}

/*输出菜单*/
void show_menu(void)
{
    show_stars(60);
    printf("%-30s%-30s\n", "1. initial strings.", "2. sorted by ASCII.");
    printf("%-30s%-30s\n", "3. sorted by string len.", "4. sorted by word len.");
    printf("%-30s\n", "5. quit.");
    show_stars(60);
}

/*输出原始字符串数组*/
void inputout(char (* input)[MAXLEN], int num)
{
    int i;
    char * pt;

    for(i = 0; i < num; i++)
    {
        pt = (char *)(input + i);
        puts(pt);
    }
}
