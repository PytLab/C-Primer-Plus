#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film * next;
};

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current, *tmp;
    char input[TSIZE];

    puts("Enter first movie title: ");
    while(gets(input) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if(head == NULL)
            head = current;
        else
            prev->next = current;
        strcpy(current->title, input);
        puts("Enter yout rating<0~10>: ");
        scanf("%d", &(current->rating));
        while(getchar() != '\n')
            continue;
        current->next = NULL;
        prev = current;
        puts("Enter next movie title:");
    }

    /*输出链表内容*/
    current = head;
    while(current != NULL)
    {
        printf("%s, rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    /*释放已分配内存*/
    current = head;
    while(current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    printf("Bye!\b");

    return 0;
}
