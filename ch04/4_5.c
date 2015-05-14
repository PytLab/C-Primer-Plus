#include <stdio.h>
#include <string.h>

int main(void)
{
    char firstname[20], lastname[20];
    int first_len, last_len;                                          //名字字段的长度

    printf("Enter your first name: \n");
    scanf("%s", firstname);
    first_len = strlen(firstname);
    printf("Enter your last name: \n");
    scanf("%s", lastname);
    last_len = strlen(lastname);

    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d\n", first_len, first_len, last_len, last_len);    //结尾对齐

    printf("%s %s\n", firstname, lastname);
    printf("%-*d %-*d\n", first_len, first_len, last_len, last_len);  //开始对齐

    return 0;
}