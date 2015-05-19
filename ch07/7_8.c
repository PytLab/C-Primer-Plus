#include <stdio.h>

#define TAXRATE1 0.15      //前300美元15%
#define TAXRATE2 0.2       //下一个150美元20%
#define TAXRATE3 0.25      //余下的为25%

int main(void)
{
    double bas_salary;
    int opt;                   //用户的选择
    void show_menu(void);      //原型声明
    void show_result(double);

    show_menu();

    printf("Your choice: ");
    scanf("%d", &opt);

    /*获取基本工资*/
    switch(opt)
    {
        case 1: bas_salary = 8.75;
                break;
        case 2: bas_salary = 9.33;
                break;
        case 3: bas_salary = 10.00;
                break;
        case 4: bas_salary = 11.20;
                break;
        case 5: puts("quit.");
                return 0;
        default: puts("quit.");
                 return 0;
    }

    show_result(bas_salary);

    return 0;
}

void show_result(double bas_salary)
{
    double hours, tot_hours;        //工作的小时数, 总工作小时
    double tot_salary, net_salary;  //总工资数, 净工资
    double tax = 0;                 //税金

    puts("Enter your working hours: ");
    scanf("%lf", &hours);

    /*获取税前工资总金额*/
    if(hours > 40.0)
        tot_hours = 40.0 + 1.5*(hours - 40.0);
    else
        tot_hours = hours;
    tot_salary = bas_salary*tot_hours;

    /*计算税金和净工资*/
    if(tot_salary > 450)
        tax = 300.0*TAXRATE1 + 150.0*TAXRATE2 + (tot_salary - 450.0)*TAXRATE3;
    else if(tot_salary > 300)
        tax = 300.0*TAXRATE1 + (tot_salary - 300)*TAXRATE2;
    else
        tax = tot_salary*TAXRATE1;
    net_salary = tot_salary - tax;

    printf("Your working hour: %.2lf\n", hours);
    printf("Total salary: %.2lf\n", tot_salary);
    printf("Tax: %.2lf\n", tax);
    printf("Net salary: %.2lf\n", net_salary);
}

void show_menu(void)
{
    void show_line(void);

    show_line();
    printf("%-25s", "1)$8.75/hr");
    printf("%-25s\n", "2)$9.33/hr");
    printf("%-25s", "3)$10.00/hr");
    printf("%-25s\n", "4)$11.20/hr");
    printf("5)quit\n");
    show_line();
}

void show_line(void)
{
    int i;
    for(i = 0; i <= 45; i++)
        putchar('*');
    putchar('\n');
}