#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

int * findClosestElements(int *arr, int arrSize, int k, int x)
{
    int *arr1 = (int *)malloc(sizeof(int)*k);
    int index = 0;
    if(arrSize == 1)
    {
        arr1[0] = arr[0];
        return arr1;
    }
    if(x > arr[arrSize-1])
    {
        int i = arrSize - k ;
        while(index != k)
        {
            arr1[index++] = arr[i++];
        }
        return arr1;
    }
    else if(x < arr[0])
    {
        int i = 0 ;
        while(index != k)
        {
            arr1[index++] = arr[i++];
        }
        return arr1;
    }
    int left = 0;
    int right = arrSize - k;
    while(left < right)
    {
        int med = (left+right)/2;
        if(x - arr[med] > arr[med + k] - x)
        {
            left = med + 1;
        }
        else
        {
            right = med;
        }
    }
    int i = left;
    while(index != k)
    {
        arr1[index++] = arr[i++];
    }
    return arr1;
}
int * findClosestElements2(int *arr, int arrSize, int k, int x)
{
   int left = 0;
   int right = arrSize-1;
   int med = 0;
   while (left+1 < right) //获取最接近x的下标
   {
        med = (right-left)/2 + left;
        if(arr[med] > x)
        {
            right = med - 1;
        }
        else
        {
            left = med + 1;
        }
   }
 
   if(abs(arr[right] - x)>=abs(arr[left] - x))//确认哪一个 下标是最接近的
   {
        med = left;
   }
   else
   {
        med = right;
   }
    left = med;
    right = med;

    while (right-left<k-1)//在该下标 向两边扩展
    {
        if(right == arrSize-1 || left!=0 && abs(arr[right] - x) >=abs(arr[left] - x))
        {
            left--;
        }
        else if(left == 0 || right!=arrSize-1 && abs(arr[right] - x) < abs(arr[left] - x))
        {
            right++;
        }
    }
    int * arr1 = (int *)malloc(sizeof(int)*k);//创键 存放数组
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        arr1[index++] = arr[left++];
    }
    return arr1;
}
int main()
{
    int arr[] = {3,5,6,7,8,12,13};
    int *arr1 =findClosestElements(arr,7,3,11);
    for (int i = 0; i < 3; i++)
    {
       printf("%d ",arr1[i]);
    }
    int *arr2 = findClosestElements2(arr,7,3,7);
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
       printf("%d ",arr2[i]);
    }
    return 0;
}