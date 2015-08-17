#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTH 41
#define MAXBKS 10

struct book{               /*建立book模板*/
    char title[MAXTITL];
    char author[MAXAUTH];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    FILE * pbooks;
    int count = 0;         /*结构计数*/
    int filecount;         /*文件中的结构计数*/
    int index;             /*结构数组索引*/
    size_t size = sizeof(struct book);  /*一个book结构所占的字节数*/
    char del;  /*是否删除的判断条件*/

    if((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat.\n", stdout);
        exit(EXIT_FAILURE);
    }
    rewind(pbooks);

    /*显示文件中的内容*/
    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if(count == 0)
            puts("Current contents of book.dat.");
        printf("%s by %s: %.2f\n", library[count].title,
               library[count].author, library[count].value);
        puts("Do you want to delete it(y|Y|n|N)?");
        del = getchar();
        getchar();  /*清空换行符*/
        if(strchr("nN", del) != NULL)
            count++;
        else if(strchr("yY", del) != NULL)
            continue;
        else
        {
            puts("Illegal input.");
            exit(EXIT_FAILURE);
        }
    }

    /*向文件中输入新内容*/
    filecount = count;  /*文件中结构的个数*/
    if(count == MAXBKS)
    {
        fputs("The book.dat file is full.\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Add new book: ");
    while(count < MAXBKS && gets(library[count].title) != NULL &&
          library[count].title[0] != '\0')
    {
        puts("Then the author: ");
        gets(library[count].author);
        puts("Now enter the value: ");
        scanf("%f", &library[count].value);
        count++;
        while(getchar() != '\n')  /*清空输入行*/
            continue;
        if(count < MAXBKS)
            puts("Another new book:");
    }

    /*在标准输出显示所有library内容,并把新book输出到文件*/
    if(count > 0)
    {
        for(index = 0; index < count; index++)
            printf("%s by %s: %.2f\n", library[index].title,
                   library[index].author, library[index].value);
        /*将结构数组内容写入文件抹掉之前的内容*/
        rewind(pbooks);  /*指针指向文件开始处*/
        fwrite(library, size, count, pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye!");
    fclose(pbooks);

    return 0;
}
