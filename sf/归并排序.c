#include <stdio.h>
#include <stdlib.h>
/* 合并左子数组和右子数组 */
void merge(int *nums, int left, int mid, int right)
{
    if(left >= right)//判读是否符合 合并排序
    {
        return;
    }
    int i = left;
    int j = mid + 1;
    int size = right - left + 1;//size一定 >= 2
    int * tep = (int *)malloc(sizeof(int)*size);//新建临时数组存放排序好的值
    int k = 0;
    while (i <= mid && j <= right)//判断左边最小值和右边最小值的大小,存入临时数组 ,直到一方全部扫描完
    {
        if (nums[i] <= nums[j])
        {
            tep[k++] = nums[i++];
        }
        else
        {
            tep[k++] = nums[j++];
        }   
    }
    //将剩余的一方在添加进尾部
    while (i <= mid)
    {
        tep[k++] = nums[i++];
    }
    while (j <= right)
    {
        tep[k++] = nums[j++];
    }
    
    for (int i = 0; i < size; i++)//将临时数组 赋值给 排序数组
    {
        nums[left + i] = tep[i];
    }
    
    free(tep);//释放
    
}

/* 归并排序 */
void mergeSort(int *nums, int left, int right)
{
    if (left >= right)//递归返回 ,当两端下标相等时
    {
        return;
    }
    //取中间值分治
    int med = (left + right) / 2;
    //先递归左 边数组
    mergeSort(nums, left, med);
    //递归右 数组
    mergeSort(nums, med + 1, right);
    //合并左右 非常像 二叉树的后序遍历 
    merge(nums, left, med, right);
}
void main()
{
    int array[5] = {1, 2, 8, 4, 5};
    mergeSort(array, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", array[i]);
    }
}