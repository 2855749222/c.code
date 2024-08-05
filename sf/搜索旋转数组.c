#include <stdio.h>

int search(int *nums,int size,int target)
{
    int left = 0; //建立左右端点
    int right = size -1;
    int min;
    while (left <= right)//获取 段点下标
    {
        int med = (right - left)/2 +left;//获取中间值
        if(nums[0] < nums[med])//判断是否有序 ,有序说明这个半区是不存在端点的
        {
            left = med+1;
        } 
        else//发现无序 这进一步判断 在什么位置
        {
            right = med-1;
            min = med;
        }
    }
    left = min;//以该段点为起点
    right = size + min - 1;//获取扩展端点
    int i;
    while (left <= right)
    {
        int med = (right - left)/2 +left; i = med%size;//每次取余 得到实际下标位置
        if(nums[i]>target)
        {
            right = med - 1;
        }
        else if (nums[i]<target)
        {
            left = med + 1;
        }
        else
        {
            return i;//找到返回下标
        }

    }
    return -1;
}
void main()
{
    int  array [10] = {4,5,6,7,8,9,10,1,2,3};
    printf("%d",search(array,10,10));
}