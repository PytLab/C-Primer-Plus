#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTH 41
#define MAXBKS 100

struct book{
    char title[MAXTITL];
    char author[MAXAUTH];
    float value;
};

void putbooks(const struct book **, int);
void srt_by_title(struct book **, int);
void srt_by_value(struct book **, int);

int main(void)
{
    struct book books[MAXBKS];
    struct book * pbooks[MAXBKS];
    int count = 0;  /*结构体计数*/

    /*初始化结构数组*/
    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.");
    while(count < MAXBKS && gets(books[count].title) != NULL &&
          books[count].title[0] != '\0')
    {
        puts("Now the author:");
        gets(books[count].author);
        puts("Value: ");
        scanf("%f", &books[count].value);
        while(getchar() != '\n')
            continue;
        /*指针数组中的指针指向结构*/
        pbooks[count] = &books[count];
        count++;
        if(count < MAXBKS)
            puts("Enter the next title.");
    }

    /*按照输入顺序输出*/
    puts("Sorted by original order:");
    putbooks(pbooks, count);
    putchar('\n');
    /*按照title首字母升序输出*/
    puts("Sorted by title:");
    srt_by_title(pbooks, count);
    putbooks(pbooks, count);
    putchar('\n');
    /*按照value升序排列*/
    puts("Sorted by value:");
    srt_by_value(pbooks, count);
    putbooks(pbooks, count);
    putchar('\n');

    return 0;
}

/*输出结构指针数组指向的结构内容*/
void putbooks(const struct book ** pbooks, int count)
{
    int i;

    for(i = 0; i < count; i++)
        printf("%s by %s: $%.2f\n", pbooks[i]->title,
               pbooks[i]->author, pbooks[i]->value);
}

/*按照title首字母升序排列*/
void srt_by_title(struct book ** pbooks, int count)
{
    int top, seek;
    struct book * tmp;

    for(top = 0; top < count-1; top++)
    {
        for(seek = top+1; seek < count; seek++)
        {
            if(strcmp(pbooks[top]->title, pbooks[seek]->title) > 0)
            {
                tmp = pbooks[top];
                pbooks[top] = pbooks[seek];
                pbooks[seek] = tmp;
            }
        }
    }
}

/*按照value升序排列指针*/
void srt_by_value(struct book ** pbooks, int count)
{
    int top, seek;
    struct book * tmp;

    for(top = 0; top < count-1; top++)
    {
        for(seek = top+1; seek < count; seek++)
        {
            if(pbooks[top]->value > pbooks[seek]->value)
            {
                tmp = pbooks[top];
                pbooks[top] = pbooks[seek];
                pbooks[seek] = tmp;
            }
        }
    }
}
