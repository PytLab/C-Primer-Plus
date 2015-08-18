#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define NSEATS 12

struct customer{
    char last[20];
    char first[20];
};

struct seat{
    int id;
    bool empty;
    struct customer customer;
};

struct seat seats[NSEATS];  /*结构数组全局变量*/

/*函数原型*/
void show_menu(void);
void init_seats(void);
int get_empty_number(void);
void putseat(const struct seat *);
void show_empty_seats(void);
void show_seats(void);
void assign(void);
void delete(void);
void archive(void);
void cleanup(void);

int main(void)
{
    char opt;

    init_seats();
    show_menu();
    printf("Your choice: ");
    while((opt = getchar()) != '\n')
    {
        cleanup();  /*清楚换行符*/
        switch(opt)
        {
            case 'a': printf("Empty seats number: %d\n", get_empty_number());
                      break;
            case 'b': show_empty_seats();
                      break;
            case 'c': show_seats();
                      break;
            case 'd': assign();
                      break;
            case 'e': delete();
                      break;
            case 'f': archive();
                      puts("Bye!");
                      exit(EXIT_SUCCESS);
        }
        putchar('\n');
        show_menu();
        printf("Your choice: ");
    }

    return 0;
}

void show_menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}

/*初始化结构数组*/
void init_seats(void)
{
    FILE * fp;
    int i;

    /*判断数据文件是否存在*/
    if((fp = fopen("seats.dat", "rb")) != NULL)  /*存在*/
    {
        fread(seats, sizeof(struct seat), NSEATS, fp);
        fclose(fp);
    }
    else  /*不存在*/
    {
        for(i = 0; i < NSEATS; i++)
        {
            seats[i].id = i;
            seats[i].empty = true;
        }
    }
}

/*获取空位个数*/
int get_empty_number(void)
{
    int i, empty_number;

    for(i = 0, empty_number = 0; i < NSEATS; i++)
    {
        if(seats[i].empty)
            empty_number++;
    }

    return empty_number;
}

/*输出一个座位的状态*/
void putseat(const struct seat * p)
{
    char customer[31];

    if(p->empty)
        printf("%5d%10s%30s\n", p->id, "Empty", "NONE");
    else
    {
        sprintf(customer, "%s-%s", p->customer.last, p->customer.first);
        printf("%5d%10s%30s\n", p->id, "Occupied", customer);
    }
}

/*输出空座位的状态*/
void show_empty_seats(void)
{
    int i;

    printf("%5s%10s%25s\n", "ID", "STATUS", "CUSTOMER");
    puts("-------------------------------------------");
    for(i = 0; i < NSEATS; i++)
    {
        if((seats+i)->empty)
            putseat(seats+i);
    }
}

void show_seats(void)
{
    int i;

    printf("%5s%10s%25s\n", "ID", "STATUS", "CUSTOMER");
    puts("-------------------------------------------");
    for(i = 0; i < NSEATS; i++)
        putseat(seats + i);
}

/*分配座位*/
void assign(void)
{
    int idx;
    
    if(get_empty_number() == 0)
    {   /*若飞机上没有空座位*/
        puts("The plane is full.");
        return;
    }
    show_empty_seats();
    puts("Enter seat number: ");
    scanf("%d", &idx);
    /*判断座位是否为空*/
    while(!seats[idx].empty)
    {
        printf("Seat %d is occupied!\n", idx);
        puts("Please enter another seat number:");
    }
    puts("Your name:");
    while(scanf("%s%s", seats[idx].customer.last, seats[idx].customer.first) != 2)
    {
        puts("Illegal name.");
        puts("Please enter your name again:");
    }
    seats[idx].empty = false;
    cleanup();
}

void delete(void)
{
    int idx;

    puts("Enter seat number: ");
    scanf("%d", &idx);
    seats[idx].empty = true;
    printf("Seat %d has been deleted.\n", idx);
    cleanup();
}

void archive(void)
{
    FILE * fp;

    if((fp = fopen("seats.dat", "wb")) == NULL)
    {
        puts("Can't open seats.dat.");
        exit(EXIT_FAILURE);
    }
    fwrite(seats, sizeof(struct seat), NSEATS, fp);
    fclose(fp);
}

void cleanup(void)
{
    while(getchar() != '\n')
        continue;
}
