#include <stdio.h>

int main(void)
{
    char choice, operator;
    float a, b, ans;
    void print_choice(void);

    while(1)
    {
        print_choice();
        scanf("%c", &choice);
        scanf("%c", &choice);

        if(choice == 'q')
        {
            puts("Bye.");
            return 0;
        }

        printf("Enter first number: ");
        while(scanf("%f", &a) != 1)
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        printf("Enter second number: ");
        while(scanf("%f", &b) != 1)
            printf("Please enter a float number: ");

        switch(choice)
        {
            case 'a':
                operator = '+';
                ans = a + b;
                break;
            case 's':
                operator = '-';
                ans = a - b;
                break;
            case 'm': 
                operator = '*';
                ans = a*b;
                break;
            case 'd':
                operator = '/';
                while(b == 0.0)
                {
                    printf("Enter a number other than 0: ");
                    scanf("%f", &b);
                }
                ans = a/b;
                break;
            case 'q':
                puts("Bye.");
                return 0;
        }

        printf("%.2f %c %.2f = %.2f\n", a, operator, b, ans);
    }
}

void print_choice(void)
{
    puts("Enter the operation of your choice: ");
    printf("%-20s", "a. add");
    printf("%-20s\n", "s. subtract");
    printf("%-20s", "m. multiply");
    printf("%-20s\n", "d. divide");
    printf("%-20s\n", "q. quit");
}