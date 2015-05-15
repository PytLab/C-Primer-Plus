#include <stdio.h>

int main(void)
{
    char pivot, charactor;
    
    for(pivot = 'F'; pivot >= 'A'; pivot--)                      //行循环
    {
        for(charactor = 'F'; charactor >= pivot; charactor--)    //列内嵌循环
            printf("%c", charactor);
        printf("\n");
    }

    return 0;
}