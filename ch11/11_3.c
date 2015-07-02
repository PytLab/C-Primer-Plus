#include <stdio.h>

int main(void)
{
    char word[11];
    void read_word(char *);

    puts("Enter some words: ");
    read_word(word);
    puts(word);

    return 0;
}

void read_word(char * word)
{
    char ch;
    int i = 0;

    ch = getchar();
    while(ch != ' ' && ch != '\n' && ch != '\t')
    {
        word[i] = ch;
        ch = getchar();
        i++;
    }
    word[i+1] = '\0';
}
