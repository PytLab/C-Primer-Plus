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

struct flight{
    int nflight;  /*航班号*/
    struct seat seats[NSEATS];
};

struct flight flights[4] = {  /*航班数组全局变量*/
    {.nflight = 102},             /*初始化航班号*/
    {.nflight = 311},
    {.nflight = 444},
    {.nflight = 519},
};

/*函数原型*/
void show_flights(void);
void show_menu(void);
void init_seats(struct flight *, int);
int get_empty_number(struct flight *);
void putseat(const struct seat *);
void show_empty_seats(struct flight *);
void show_seats(struct flight *);
void assign(struct flight *);
void delete(struct flight *);
void archive(struct flight *, int);
void cleanup(void);

int main(void)
{
    char opt;
    int fidx, nflight;        /*航班索引号, 航班号*/
    struct flight * pflight;  /*指向当前航班*/

    show_flights();
    printf("Your choice: ");
    while(scanf("%d", &fidx) == 1)
    {
        cleanup();
        if(fidx > 3)
        {
            puts("Enter number 0 ~ 3...");
            continue;
        }
        pflight = flights + fidx;      /*指针指向选择的航班*/
        nflight = pflight->nflight;    /*选择航班的航班号*/

        init_seats(pflight, nflight);  /*初始化座位*/
        show_menu();
        printf("@flight%d> ", nflight);
        while((opt = getchar()) != '\n')
        {
            cleanup();  /*清楚换行符*/
            switch(opt)
            {
                case 'a': printf("Empty seats number: %d\n",
                                 get_empty_number(pflight));
                          break;
                case 'b': show_empty_seats(pflight);
                          break;
                case 'c': show_seats(pflight);
                          break;
                case 'd': assign(pflight);
                          break;
                case 'e': delete(pflight);
                          break;
                case 'f': archive(pflight, nflight);
                          puts("Bye!");
                          break;
            }
            if(opt == 'f')
                break;
            putchar('\n');
            show_menu();
            printf("@flight%d>", nflight);
        }
        show_flights();
        printf("Your choice: ");
    }

    return 0;
}

void show_flights(void)
{
    puts("To choose a flight, enter its choice number:");
    puts("0) flight-102");
    puts("1) flight-311");
    puts("2) flight-444");
    puts("3) flight-519");
    puts("Enter q to quit.");
}

void show_menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Return");
}

/*初始化指定航班的座位结构数组*/
void init_seats(struct flight * p, int nflight)
{
    FILE * fp;
    int i;
    char filename[31];

    sprintf(filename, "flight_%d.dat", nflight);
    /*判断数据文件是否存在*/
    if((fp = fopen(filename, "rb")) != NULL)  /*存在*/
    {
        fread(p->seats, sizeof(struct seat), NSEATS, fp);
        fclose(fp);
    }
    else  /*不存在*/
    {
        for(i = 0; i < NSEATS; i++)
        {
            p->seats[i].id = i;
            p->seats[i].empty = true;
        }
    }
}

/*获取空位个数*/
int get_empty_number(struct flight * p)
{
    int i, empty_number;

    for(i = 0, empty_number = 0; i < NSEATS; i++)
    {
        if(p->seats[i].empty)
            empty_number++;
    }

    return empty_number;
}

/*输出一个座位的状态*/
void putseat(const struct seat * p)
{
    char customer[31];

    if(p->empty)
        printf("%5d%10s%25s\n", p->id, "Empty", "NONE");
    else
    {
        sprintf(customer, "%s-%s", p->customer.last, p->customer.first);
        printf("%5d%10s%25s\n", p->id, "Occupied", customer);
    }
}

/*输出空座位的状态*/
void show_empty_seats(struct flight * p)
{
    int i;

    printf("%5s%10s%25s\n", "ID", "STATUS", "CUSTOMER");
    puts("-------------------------------------------");
    for(i = 0; i < NSEATS; i++)
    {
        if(((p->seats) + i)->empty)
            putseat((p->seats) + i);
    }
}

void show_seats(struct flight * p)
{
    int i;

    printf("%5s%10s%25s\n", "ID", "STATUS", "CUSTOMER");
    puts("-------------------------------------------");
    for(i = 0; i < NSEATS; i++)
        putseat((p->seats) + i);
}

/*分配座位*/
void assign(struct flight * p)
{
    int idx;
    
    if(get_empty_number(p) == 0)
    {   /*若飞机上没有空座位*/
        puts("The flight is full.");
        return;
    }
    show_empty_seats(p);
    puts("Enter seat number: ");
    scanf("%d", &idx);
    /*判断座位是否为空*/
    if(!p->seats[idx].empty)
    {
        printf("Seat %d is occupied!\n", idx);
        cleanup();
        return;
    }
    puts("Your name:");
    while(scanf("%s%s",
                p->seats[idx].customer.last,
                p->seats[idx].customer.first) != 2)
    {
        puts("Illegal name.");
        puts("Please enter your name again:");
    }
    p->seats[idx].empty = false;
    cleanup();
}

void delete(struct flight * p)
{
    int idx;

    puts("Enter seat number: ");
    scanf("%d", &idx);
    p->seats[idx].empty = true;
    printf("Seat %d has been deleted.\n", idx);
    cleanup();
}

void archive(struct flight * p, int nflight)
{
    FILE * fp;
    char filename[31];

    sprintf(filename, "flight_%d.dat", nflight);
    if((fp = fopen(filename, "wb")) == NULL)
    {
        puts("Can't open seats.dat.");
        exit(EXIT_FAILURE);
    }
    fwrite(p->seats, sizeof(struct seat), NSEATS, fp);
    fclose(fp);
}

void cleanup(void)
{
    while(getchar() != '\n')
        continue;
}
