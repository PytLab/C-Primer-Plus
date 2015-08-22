#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void showmovie(Item);

int main(void)
{
    List movies;
    Item film;

    InitialList(&movies);

    if(ListIsFull(&movies))
    {
        puts("No memory available! Bye!");
        exit(EXIT_FAILURE);
    }

    puts("Enter first movie title: ");
    while(gets(film.title) != NULL && film.title[0] != '\0')
    {
        puts("Enter your rating<0 ~ 10>: ");
        scanf("%d", &film.rating);
        while(getchar() != '\n')
            continue;
        /*将film添加到列表*/
        if(AddItem(film, &movies) == false)
        {
            puts("Problem allocating memory");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter the next movie title:");
    }

    /*显示*/
    if(ListIsEmpty(&movies))
        puts("List is empty.");
    else
    {
        puts("Here is the movies:");
        Apply(showmovie, &movies);
    }
    printf("You have entered %d movies.\n", ListItemCount(&movies));

    /*清除内存*/
    FreeList(&movies);
    puts("Bye!");

    return 0;
}

void showmovie(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
}
