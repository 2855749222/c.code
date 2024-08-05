#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int tom[numsSize];
    int index = 0;
    int size = numsSize;
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i] == val)
        {
            size--;
            continue;
        }
        tom[index++] = nums[i];
    }
     for(int i = 0; i<size;i++)
    {
        nums[i] = tom[i];
    }
    for (int i = 0; i<size; i++)
    {
        
        printf("%d ",nums[i]);
    }
    return  size;
}
void main()
{
    int arr[4] = {3,2,2,3};
    int n = removeElement(arr,4,3);
   
    
}