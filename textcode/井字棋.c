#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cleararray(char **Chessboard);
int insert(char **Chessboard, int num, char ch);
void palygame(char **Chessboard);
int same(char **Chessboard);
void show(char **Chessboard);
int insert(char **Chessboard, int num, char ch)//插入棋子
{
    if (num < 4)
    {
        if (Chessboard[0][num - 1] == 'O' || Chessboard[0][num - 1] == 'X')
        {
            printf("\n已经有棋子了,请重新输入\n");
            sleep(1);
            return 0;
        }

        Chessboard[0][num - 1] = ch;
    }
    else if (num < 7 && num > 3)
    {
        if (Chessboard[1][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] == 'O' || Chessboard[1][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] == 'X')
        {
            printf("\n已经有棋子了,请重新输入\n");
            sleep(1);
            return 0;
        }
        Chessboard[1][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] = ch;
    }
    else
    {
        if (Chessboard[2][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] == 'O' || Chessboard[2][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] == 'X')
        {
            printf("\n已经有棋子了,请重新输入\n");
            sleep(1);
            return 0;
        }
        Chessboard[2][num % 3 != 0 ? num % 3 - 1 : num % 3 + 2] = ch;
    }
    return 1;
}
void palygame(char **Chessboard)//游戏函数
{
    int play1;
    int play2;
    int i = 0;
    int count = 0;
    while (i < 9) // 最多输入9个
    {
        count+=2;
        printf("请play1 下子:");
        scanf("%d", &play1);
        while (!insert(Chessboard, play1, 'X')) // 判读是否有相同的
        {
            show(Chessboard);
            printf("请play1重新下子:");
            scanf("%d", &play1);
        }
        show(Chessboard);
        if (same(Chessboard) == 1)
        {
            printf("是 play1赢了!\n");
            break;
        }
        if (count == 10)
        {
            printf("\n平局!\n");
            break;
        }
        
        printf("请play2 下子:");
        scanf("%d", &play2);
        while (!insert(Chessboard, play2, 'O'))
        {
            show(Chessboard);
            printf("请play2重新下子:");
            scanf("%d", &play2);
        }
        show(Chessboard);
        if (same(Chessboard) == 2)
        {
            printf("是 play2赢了!\n");
            break;
        }
        i++;

    }
    cleararray(Chessboard);
}
int same(char **Chessboard)//判读是否赢游戏
{
    int sum = 0;
    for (int i = 0; i < 3; i++)//第一种 横排
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += Chessboard[i][j];
        }
        if (sum == 264)
        {
            return 1;
        }
        else if (sum == 237)
        {
            return 2;
        }
    }

    for (int i = 0; i < 3; i++)//第二种 竖排
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += Chessboard[j][i];
        }
        if (sum == 264)
        {
            return 1;
        }
        else if (sum == 237)
        {
            return 2;
        }
    }
    int X1 = Chessboard[0][0] + Chessboard[1][1] + Chessboard[2][2] + 0;
    int X2 = Chessboard[0][2] + Chessboard[1][1] + Chessboard[2][0] + 0;
    if (X1 == 264 || X2 == 264) //两种交叉情况
    {
        return 1;
    }
    else if (X1 == 237 || X2 == 237)
    {
        return 2;
    }

    return 0;
}
void cleararray(char **Chessboard)//清除棋盘
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Chessboard[i][j] = '0';
        }
    }
}

void show(char **Chessboard)//show
{
    system("clear");
    int board[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c  ", Chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n**********************************\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    char **Chessboard = (char **)malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++)
    {
        Chessboard[i] = (char *)malloc(sizeof(char) * 3);
    }
    //初始化
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Chessboard[i][j] = '0';
        }
    }
    int input = 0;
    int i = 0;
    while (i < 5)
    {
        printf("请选择:");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            palygame(Chessboard);
            break;
        case 2:
            show(Chessboard);
            return 0;
        case 3:
            return 0;
        }
        i++;
    }
    for (int i = 0; i < 3; i++)
    {
        free(Chessboard[i]);
        Chessboard[i] = NULL;
    }
    free(Chessboard);
    Chessboard = NULL;
}