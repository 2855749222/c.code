#include <stdio.h>
#include <string.h>

void fun(int *array, int size)
{
    // 外循环：已排序区间为 [0, i-1]
    for (int i = 0; i < size - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[k])
            {
                k = j; // 记录最小元素的索引
            }
        }
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

int main()
{
    int array[] = {5, 1, 7, 81, 8, 16, 5, 9, 148, 1};
    fun(array, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
