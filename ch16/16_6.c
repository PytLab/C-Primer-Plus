#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALEN 5
#define SLEN 40

typedef struct{
    char first[SLEN];
    char last[SLEN];
} NAME;

void show_array(NAME *);
int mycomp(const void *, const void *);

int main(void)
{
    NAME names[ALEN] = {
        {"Shao", "Zhengjiang"},
        {"Torres", "Fernando"},
        {"Kobe", "Bryant"},
        {"Mata", "Juan"},
        {"Cao", "Xiaoming"},
    };

    puts("Original order:");
    show_array(names);
    qsort(names, ALEN, sizeof(NAME), mycomp);
    puts("\nSorted array:");
    show_array(names);

    return 0;
}

void show_array(NAME * names)
{
    for(int i = 0; i < ALEN; i++)
        printf("%s-%s\n", names[i].first, names[i].last);
}

int mycomp(const void * p1, const void * p2)
{
    const NAME * a1, * a2;

    a1 = (const NAME *)p1;
    a2 = (const NAME *)p2;

    if(strcmp(a1->first, a2->first) == 0)
        return strcmp(a1->last, a2->last);
    else
        return strcmp(a1->first, a2->first);
}
