#include <stdio.h>
/*是否透明*/
#define YES 1
#define NO 0
/*边框样式*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/*三原色*/
#define BLUE 4
#define GREEN 2
#define RED 1
/*混合颜色*/
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow",
                          "blue", "magenta", "cyan", "white"};

struct box_prop{
    unsigned int opaque         :1;
    unsigned int fill_color     :3;
    unsigned int                :4;
    unsigned int show_border    :1;
    unsigned int border_color   :3;
    unsigned int border_style   :2;
    unsigned int                :2;
};

void show_settings(struct box_prop *);

int main(void)
{
    struct box_prop box = {YES, YELLOW, YES, GREEN, DASHED};
    puts("Original box setting: \n");
    show_settings(&box);

    box.opaque = NO;
    box.fill_color = GREEN;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}

void show_settings(struct box_prop * p)
{
    printf("Box is %s.\n", p->opaque == YES ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[p->fill_color]);
    printf("Border %s.\n", p->show_border == YES ? "shown" : "not shown");
    printf("Border color is %s.\n", colors[p->border_color]);
    printf("Border style is ");
    switch(p->border_style)
    {
        case SOLID: printf("solid.\n"); break;
        case DASHED: printf("dashed\n"); break;
        case DOTTED: printf("dotted\n"); break;
        default: printf("unknown type.\n");
    }
}
