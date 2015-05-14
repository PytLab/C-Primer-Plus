#include <stdio.h>

int main(void)
{
    float height;

    printf("Enter your height:\n");
    scanf("%f", &height);

    printf("Dabney, you are %.3f feet tall.\n", height);

    return 0;
}