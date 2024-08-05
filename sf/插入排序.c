#include <stdio.h>
#include <string.h>

void fun(int *array,int size)
{
  // 外循环：已排序区间为 [0, i-1]
    for (int i = 1; i < size; i++) {
        int base = array[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间 [0, i-1] 中的正确位置
        while (j >= 0 && array[j] > base) {
            // 将 nums[j] 向右移动一位
            array[j + 1] = array[j];
            j--;
        }
        // 将 base 赋值到正确位置
        array[j + 1] = base;
    }
   
}

int main()
{
    int array[] = {5, 1, 7, 81, 8, 16, 5, 9, 148, 1};
    fun(array,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
