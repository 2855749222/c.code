#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct listarray
{
    int size;
    int data[MAX_SIZE];

}Array;
Array * craetarray()
{
    Array *array = (Array*)malloc(sizeof(Array));
    array->size = 0;
}
void insertnum(Array * array,int num)
{
    if (array->size == MAX_SIZE )
    {
        printf("已满!");
        return;
    }    
    array->data[array->size++] = num;
}
void showArray(Array * array)
{
    for (int i = 0; i < array->size; i++)
    {
        printf("%d ",array->data[i]);
    }
    
}
int findArray(Array * array,int num)
{
    int n = 0;
    int m = array->size-1;
    int i = 0;
    i = (m-n)/2+n;
    while (n <= m)
    {
        
        if (array->data[i] == num)
        {
            printf("找到");
            return i;
        }
        else if(array->data[i] > num)//判断 查找值小于中间值 在左边
        {
            m = i-1;//m前移
            i = (m-n)/2+n;
        }
        else if (array->data[i] < num)//判断 查找值大于中间值 在右边
        {
            n = i+1;//i后移
            i = (m-n)/2+n;// (4-3/2) + 3 = 3 所以需要加一或者减一移动前后下标
        }
    }
    return -1;
}
int main()
{
    Array * array = craetarray();
    for (int i = 0; i < MAX_SIZE ;i++)
    {
        insertnum(array,i);
    }
    showArray(array);
    int pos = findArray(array,9);
    printf("%d",pos);
    free(array);

}