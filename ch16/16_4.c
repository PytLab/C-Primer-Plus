#include <stdio.h>
#include <time.h>

void sleep(float);

int main(void)
{
    float t;
    puts("Enter sleep time: ");
    while(scanf("%f", &t) == 1)
    {
        sleep(t);
        puts("Time is up!");
        puts("Enter again: ");
    }

    return 0;
}

void sleep(float t)
{
    time_t begin;

    begin = clock();
    while((float)((clock() - begin)/CLOCKS_PER_SEC) < t)
    {}
}
