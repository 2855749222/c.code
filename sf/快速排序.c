#include <stdio.h>
#include <string.h>

int partition(int *array, int left, int right) // 哨兵划分
{
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && array[j] >= array[left]) // 从右向左找首个小于基准数的元素
        {
            j--;
        }
        while (i < j && array[i] <= array[left]) // 从左向右找首个大于基准数的元素
        {
            i++;
        }
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
    int temp = array[left];
    array[left] = array[i];
    array[i] = temp;
    return i;
}

/* 快速排序 */
void quickSort(int *nums, int left, int right)
{
    // 子数组长度为 1 时终止递归
    if (left >= right)
    {
        return;
    }
    // 哨兵划分
    int pivot = partition(nums, left, right);
    // 递归左子数组、右子数组
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}
int main()
{
    int array[] = {5, 1, 7, 81, 8, 16, 5, 9, 148, 1};
    quickSort(array,0,9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
