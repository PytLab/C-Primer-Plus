#include <stdio.h>
#include <string.h>

struct month{
    char name[10];
    char abbrev[5];
    int days;
    int monumb;
};

void cleanup(void);
int sum_monumb(const struct month *, int);
int sum_mname(const struct month *, char *);

static struct month months[12] = 
{
    {"January", "jan", 31, 1},
    {"February", "feb", 28, 2},
    {"March", "mar", 31, 3},
    {"April", "apr", 30, 4},
    {"May", "may", 31, 5},
    {"June", "jun", 30, 6},
    {"July", "jul", 31, 7},
    {"August", "aug", 31, 8},
    {"September", "sep", 30, 9},
    {"October", "oct", 31, 10},
    {"November", "nov", 30, 11},
    {"December", "dec", 31, 12},
};

int main(void)
{
    int year, day, monumb;
    int sum, sub_sum; /*天数总和*/
    char mname[10];

    puts("Enter a year: ");
    while(scanf("%d", &year) == 1)
    {
        /*判断是否是闰年*/
        if((year%4 == 0 && year%100 != 0) || year%400 == 0)
            months[1].days = 29;
        puts("Enter day: ");
        cleanup();  /*清空输入行*/
        scanf("%d", &day);
        cleanup();  /*清空输入行*/
        puts("Enter month: ");
        if(scanf("%d", &monumb) == 1)  /*用户输入是数字*/
            sub_sum = sum_monumb(months, monumb);
        else if(scanf("%s", mname) == 1)  /*用户输入字符串*/
            sub_sum = sum_mname(months, mname);
        sum = sub_sum + day;
        printf("There are %d days.\n", sum);
        puts("Enter a another year: ");
    }

    return 0;
}

/*返回当月之前所有月份的天数,不包括本月*/
int sum_monumb(const struct month * p, int monumb)
{
    int i, sum;

    for(i = 0, sum = 0; i < monumb-1; i++)
        sum += (p+i)->days;

    return sum;
}

int sum_mname(const struct month * p, char * mname)
{
    int i = 0, sum = 0;

    while(strcmp(mname, (p+i)->name) != 0 &&
          strcmp(mname, (p+i)->abbrev) != 0)
    {
        sum += (p+i)->days;
        i++;
    }

    return sum;
}

void cleanup(void)
{
    while(getchar() != '\n')
        continue;
}
