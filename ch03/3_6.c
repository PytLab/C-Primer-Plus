#include <stdio.h>
#define WATERMASS 3.0e-23  //一个水分子质量
#define QUARKMASS 950.0        //1夸克水的质量

int main(void)
{
    double quark;
    double mol_num;

    printf("Enter quark number: \n");
    scanf("%lf", &quark);

    mol_num = QUARKMASS*quark/WATERMASS;

    printf("There are %e water molecules.\n", mol_num);

    return 0;
}