#include <stdio.h>
#define CSIZE 4

struct names{
    char last[40];
    char first[40];
};

struct student{
    struct names name;
    float grade[3];
    float avg;
};

void get_grades(struct student *);
void get_avg(struct student *);
void putstudents(struct student *);
float * get_avgs(struct student *, float *);

int main(void)
{
    struct student students[CSIZE] = {
        {.name = {"Zhengjiang", "Shao"}},
        {.name = {"Fernando", "Torres"}},
        {.name = {"Kobe", "Bryant"}},
        {.name = {"Xabi", "Alonso"}},
    };
    float avgs[3];

    get_grades(students);
    get_avg(students);
    putstudents(students);
    get_avgs(students, avgs);
    printf("avgs: %.2f, %.2f, %.2f\n", avgs[0], avgs[1], avgs[2]);

    return 0;
}

/*提示用户输入每个人的成绩*/
void get_grades(struct student * students)
{
    int i;

    for(i = 0; i < CSIZE; i++)
    {
        printf("Enter 3 grades for %s-%s: ",
               students[i].name.last, students[i].name.first);
        scanf("%f%f%f", students[i].grade,
              students[i].grade+1, students[i].grade+2);
    }
}

void get_avg(struct student * students)
{
    int i;
    float avg;

    for(i = 0; i < CSIZE; i++)
    {
        avg = (students[i].grade[0] + students[i].grade[1] + 
               students[i].grade[2])/3.0;
        students[i].avg = avg;
    }
}

/*输出结构数组中的信息*/
void putstudents(struct student * students)
{
    int i;

    for(i = 0; i < CSIZE; i++)
        printf("Name: %s %s, Grades: %.2f %.2f %.2f, average: %.2f\n",
               students[i].name.last, students[i].name.first,
               students[i].grade[0], students[i].grade[1],
               students[i].grade[2], students[i].avg);
}

/*获取每一科的平均分数*/
float * get_avgs(struct student * students, float * avgs)
{
    float sums[3] = {0.0};
    int i;

    for(i = 0; i < CSIZE; i++)
    {
        sums[0] += students[i].grade[0];
        sums[1] += students[i].grade[1];
        sums[2] += students[i].grade[2];
    }
    for(i = 0; i < 3; i++)
        avgs[i] = sums[i]/CSIZE;

    return avgs;
}
