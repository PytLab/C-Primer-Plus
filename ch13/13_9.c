#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int main(void)
{
    FILE * fp;
    char word[MAX];
    int idx = 1;  /*单词编号*/

    if((fp = fopen("ch13.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"ch13.txt\".\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter some words:");
    while(gets(word) != NULL && word[0] != '\0')
    {
        fprintf(fp, "%s ", word);
        puts("another word: ");
    }
    /*输出单词*/
    rewind(fp);
    while(fscanf(fp, "%s", word) == 1)
    {
        fprintf(stdout, "%d: %s\n", idx, word);
        idx++;
    }
    fclose(fp);

    return 0;
}