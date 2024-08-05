#include <stdio.h>
#include <stdlib.h>
void show(int **count, int N, int M);

void show(int **count, int N, int M)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d  ", count[i][j]);
        }

        printf("\n");
    }
}
int main()
{
    int N, M;
    printf("请输入 二维数组的排:");
    scanf("%d", &N);
    printf("请输入 二维数组的列:");
    scanf("%d", &M);
    int **count = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        count[i] = (int *)malloc(M * sizeof(int *));
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            count[i][j] = rand() % 100;
        }
    }
    show(count, N, M);
    for (int i = 0; i < N; i++)
    {
        free(count[i]);
        count[i] = NULL;
    }
    free(count);
    count = NULL;

    return 0;
}