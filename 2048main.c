#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "merge.h"
#define version "0.1"

//主菜单函数
int showmenu();

//判断游戏是否结束
int gamecontinue(int (*arr)[4]);

//在地图上生成一个随机数，k为出现4的概率，否则出现2
void newnum(int (*map)[4], double k);

//打印地图
int showmap(int (*map)[4], int score);

//统计目前的得分
int scoremap(int map[][4]);

//游戏主函数
void game();

//高分榜主函数
void scores();

//主函数
int main(void)
{
    printf("Welcome to 2048 Version: 0.1 Powered by Jin_Wenze:\n");
    system("pause");
    system("cls");
    int running = 1;
    while(running)
    {
        int selection = showmenu();
        if(selection == 3) break;
        switch(selection)
        {
            case 1:
                game();
                break;
            case 2:
                scores();
                break;
            case 3:
                running = 0;
                break;
        }
    }
    system("cls");
    printf("...Powered by Jin_Wenze...\n");
    system("pause");
    return 0;
}


int gamecontinue(int (*arr)[4])
{
    int map[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = arr[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i < 5; i++)count += merge(map,i);
    if(count == 0) return 0;
    else return 1;
}

int showmap(int (*map)[4],int score)
{
    printf("得分：  %d\n", score);
    for(int i = 0; i < 4; i++)
    {
        printf("%d\t%d\t%d\t%d\n\n", map[i][0], map[i][1], map[i][2], map[i][3]);
    }
}

int showmenu()
{
    printf("请输入相应的字母来选择\n");
    printf("1.开始游戏\n");
    printf("2.高分榜 (不可用)\n");        //后期通过文件输入输出实现
    printf("3.退出\n");
    int x;
    scanf("%d",&x);                                  //后期加入输入检验
    return x;
}

void game()
{
    //进行游戏初始化
    int map[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = 0;
        }
    }
    
    int move = 0;
    while(1)
    {
        system("cls");
        newnum(map, 0.7);               //参数设置部分待完成
        showmap(map,scoremap(map));
        if(gamecontinue(map) == 0) break;
        int check = 0;                  //检验操作是否有意义
        while(check == 0)
        {
            printf("输入数字进行操作: 1 向上 2 向下 3 向左 4 向右\n");
            scanf("%d", &move);             //输入检验待完成
            check = merge(map, move);
            if(check == 0) printf("操作无效，");
        }
    }
    printf("游戏已结束！\n");
}

void scores()
{
    system("cls");
    printf("Runing function scores\n");
}

void newnum(int (*map)[4], double k)
{
    srand((unsigned)time(NULL));
    int count = 0; //用于统计地图中有多少0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++) if(map[i][j] == 0) count ++;
    }
    int seed = rand() % count + 1;
    count = 0;
    int notdone = 1;
    for(int i = 0; i < 4 && notdone; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] == 0)
            {
                count ++;
                if(count == seed)
                {
                    double iftwo = rand() % 100 / 100.0;
                    if(iftwo < k) map[i][j] = 2;
                    if(iftwo >= k) map[i][j] = 4;
                    notdone = 0;
                    break;
                }
            }
        }
    }
}

int scoremap(int map[][4])
{
    int score = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            score += map[i][j];
        }
    }
    return score;
}

