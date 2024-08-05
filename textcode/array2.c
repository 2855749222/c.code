#include <stdio.h>
#include <stdlib.h>

void reed_input(int **array ,int N)
{
    for (int i = 0; i < N; i++)
    {
       printf("\n输入第%d位同学的成绩:",i+1);
       for (int j = 0; j < N; j++)
       {
           
            scanf("%d",&array[i][j]);
       }
       
    }
    
    
}
void show(int **array,int N)
{
    for (int i = 0; i < N; i++)
    {
       printf("\n第%d位同学的成绩:",i+1);
       for (int j = 0; j < N; j++)
       {
            printf("%d",array[i][j]);
       }
        
    }
}
void student_average(int **array ,int N)
{
    int average[5];
    int M = 1;
    for(int i = 0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
       {
          M += array[i][j];
       }
       average[i] = M/N;
       M = 1;
    }
    for (int i = 0; i < N; i++)
    {
       printf("\n第%d位同学的平均成绩: %d",i+1,average[i]);
    }
    
}
void class_average(int **array ,int N)
{
    int average[5];
    int M = 1;
    for(int i = 0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
       {
          M += array[j][i];
       }
       average[i] = M/N;
       M = 1;
    }
    for (int i = 0; i < N; i++)
    {
       printf("\n第%d门学科的平均成绩: %d",i+1,average[i]);
    }

}
int main()
{
    //动态分配二维数组内存
    int **array = (int **)malloc(5*sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        array[i] = (int *)malloc(5*sizeof(int));
    }
    reed_input(array,5);
    // show(array,5);  
    //求每位学生的平均成绩
    student_average(array,5);
    //求每门课的平均成绩
    class_average(array,5);

    //释放内存
    for (int i = 0; i < 5; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
    
}