#include <stdio.h>

int main(void)
{
    const int convert = 60;
    int min, sec;
    float hour;

    printf("Enter time in minutes(minus to stop): \n");
    while((scanf("%d", &min) == 1) && (min >= 0))
    {
        hour = min/(float)convert;
        sec = min*convert;
        printf("%dmin = %fh = %dsec\n", min, hour, sec);
        printf("Enter another time in minutes:\n");
    }

    return 0;
}