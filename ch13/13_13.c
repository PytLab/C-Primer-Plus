#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROW 20
#define COL 30
#define LLEN 101

void parse(char *);
void convert(int (*)[COL]);
void put_intmat(int (*)[COL], int);
void put_charmat(char (*)[COL], int);
void flatten(void);

static const char map[10] = {' ', '.', '\'', ':', '~', '*', '=', '<', '%', '#'};
static char cmat[ROW][COL+1];  /*字符阵列*/
static int mat[ROW][COL];  /*保存数值的阵列*/

int main(int argc, char * argv[])
{
    char * file = argv[1];
    int i;  /*输出循环计数*/
    FILE * fout;

    /*将文件内容读入到int数组中*/
    parse(file);

    /*消除尖峰脉冲*/
    flatten();

    /*转换成字符阵列*/
    convert(mat);

    /*输出字符阵列*/
    if((fout = fopen("OUT.txt", "w")) == NULL)
    {
        printf("Can't open %s\n", "OUT.txt");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < ROW; i++)
    {
        fputs((char *)cmat[i], fout);
        putc('\n', fout);
        puts((char *)cmat[i]);  /*cmat[i][0]*/
    }

    fclose(fout);

    return 0;
}

/*解析文件, 将文件内容读入到int数组中*/
void parse(char * file)
{
    FILE * fin;
    int i, j;           /*循环计数*/
    int k;              /*每行字符串循环计数*/
    char line[LLEN];    /*每行字符串数组*/
    char ch;

    if((fin = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < ROW; i++)
    {
        fgets(line, LLEN, fin);
        k = 0;
        j = 0;  /*数组中列计数*/
        while((ch = line[k]) != '\0')
        {
            if(isdigit(ch))
            {
                mat[i][j] = (int)(ch - '0');  /*字符转int*/
                j++;
            }
            k++;
        }
    }

    fclose(fin);
}

/*将int阵列转换成对应字符阵列*/
void convert(int (* mat)[COL])
{
    int i,j;
    char ch;
    int idx;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            idx = mat[i][j];
            ch = map[idx];
            cmat[i][j] = ch;
        }
        cmat[i][COL] = '\0';
    }
}

/*输出int二维数组*/
void put_intmat(int mat[][COL], int m)
{
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < COL; j++)
            printf("%d ", mat[i][j]);
        putchar('\n');
    }
}

/*输出char二维数组*/
void put_charmat(char mat[][COL], int m)
{
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < COL; j++)
            printf("%c ", mat[i][j]);
        putchar('\n');
    }
}

void flatten(void)
{
    int i, j, avg, left, up, right, down, center;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            center = mat[i][j];
            /*阵列四个顶角的元素*/
            if(i == 0 && j == 0)  /*左上*/
            {
                down = mat[i+1][j];
                right = mat[i][j+1];
                if((center - down) > 1 && (center - down) > 1)
                {
                    avg = (down + right)/2;
                    center = avg;
                }
            }
            else if(i == 0 && j == COL-1)  /*右上*/
            {
                left = mat[i][j-1];
                down = mat[i+1][j];
                if((center - left) > 1 && (center - down) > 1)
                {
                    avg = (left + down)/2;
                    center = avg;
                }
            }
            else if(i == ROW-1 && j == 0)  /*左下*/
            {
                up = mat[i-1][j];
                right = mat[i][j+1];
                if((center - up) > 1 && (center - right) > 1)
                {
                    avg = (up + right)/2;
                    center = avg;
                }
            }
            else if(i == ROW-1 && j == COL-1)  /*右下*/
            {
                left = mat[i-1][j];
                up = mat[i][j-1];
                if((center - left) > 1 && (center - up) > 1)
                {
                    avg = (left + up)/2;
                    center = avg;
                }
            }
            /*边界上的元素*/
            else if(j == 0 && i < ROW-1 && i > 0)  /*左边界*/
            {
                up = mat[i-1][j];
                right = mat[i][j+1];
                down = mat[i+1][j];
                if((center - up) > 1 && (center - right) > 1 && (center - down) > 1)
                {
                    center = (up + right + down)/3;
                    center = avg;
                }
            }
            else if(i == 0 && j < COL-1 && j > 0)  /*上边界*/
            {
                left = mat[i][j-1];
                down = mat[i+1][j];
                right = mat[i][j+1];
                if((center - left) > 1 && (center - down) > 1 && (center - right) > 1)
                {
                    avg = (left + down + right)/3;
                    center = avg;
                }
            }
            else if(j == COL-1 && i < ROW-1 && i > 0)  /*有边界*/
            {
                up = mat[i-1][j];
                left = mat[i][j-1];
                down = mat[i+1][j];
                if((center - up) > 1 && (center - left) > 1 && (center - down) > 1)
                {
                    avg = (up + left + down)/3;
                    center = avg;
                }
            }
            else if(i == ROW-1 && j < COL-1 && j > 0)  /*下边界*/
            {
                left = mat[i][j-1];
                up = mat[i-1][j];
                right = mat[i][j+1];
                if((center - left) > 1 && (center - up) > 1 && (center - right) > 1)
                {
                    avg = (left + up + right);
                    center = avg;
                }
            }
            else
            {
                left = mat[i][j-1];
                up = mat[i-1][j];
                right = mat[i][j+1];
                down = mat[i+1][j];
                if((center - left) > 1 && (center - up) > 1 &&
                   (center - right) > 1 && (center - down) > 1)
                {
                    avg = (left + up + right + down)/4;
                    center = avg;
                }
            }
        }
    }
}
