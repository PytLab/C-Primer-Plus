#include <stdio.h>

struct names{
    char last[20];
    char middle[20];
    char first[20];
};
struct person{
    char id[25];
    struct names name; 
};

void putpeople(const struct person *);

int main(void)
{
    const struct person people[5] = {  /*初始化结构数组*/
        {"302029823", {"Dribble", "Flossie", "Mcgrady"}},
        {"101002323", {"Jiang", "Zheng", "Shao"}},
        {"101002324", {"Fernando", "", "Torres"}},
        {"101002325", {"Oliver", "Iker", "Casillas"}},
        {"101002326", {"Hzard", "", "Kaka"}},
    };

    putpeople(people);

    return 0;
}

void putpeople(const struct person * people)
{
    int i;

    for(i = 0; i < 5; i++)
        printf("%s, %s %c. - %s\n",
               people[i].name.last, people[i].name.middle,
               people[i].name.first[0], people[i].id);
}
