#include <stdio.h>

#define BASIC_SALARY 10.0  //10.00美元/小时
#define TAXRATE1 0.15      //前300美元15%
#define TAXRATE2 0.2       //下一个150美元20%
#define TAXRATE3 0.25      //余下的为25%

int main(void)
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
    tot_salary = BASIC_SALARY*tot_hours;

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

    return 0;
}