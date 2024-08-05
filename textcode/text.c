#include <stdio.h>
#include "text.h"
#include <string.h>
#include <stdlib.h>
char * fuh(char *p)
{
    p = (char*)malloc(100);
    strcpy(p,"asdasd");
    // return p;
}
int search(int* nums, int numsSize) 
{
     int min = 0;
     int r = numsSize - 1;
     int m;
    for (int l = 0; l < r;) {
        m = (l + r) / 2;
        if (nums[0] < nums[m]) l = m + 1;
        else { r = m - 1; min = m; }
    }
    return min;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  int left = 0;
    int right = numsSize - 1;
    int index = 0;
    int med;
    int *pos = (int *)malloc(sizeof(int)*2);
    if(left > right)
    {
        pos[0] = -1;
        pos[1] = -1;
        return pos;
    }
     * returnSize = 2;
    if(left == right)
    {
        if(nums[left] == target)
        {
           pos[0] = 0;
           pos[1] = 0;
           return pos;
        }
        pos[0] = -1;
        pos[1] = -1;
        return pos;
    }
    while(left <= right)
    {
        med = (right+left)/2;
        if(nums[med] >= target)
        {
            right = med - 1; 
            pos[0] = med;
        }
        else
        {
            left = med+1; 
        }
    }
   
  
    left = 0;
    right = numsSize - 1;
    while(left <= right )
    {
        med = (right+left)/2;  
        if(nums[med] <= target)
        {
            left = med+1; 
            pos[1] = med;
        }
        else
        {
            right = med - 1;
        }
    }
   
   
    if(nums[pos[0]] != target || nums[pos[1]] != target)
    {
        pos[0] = -1;
        pos[1] = -1;
    }
    return pos;
}
int main()
{
    // char a[10]={0};
    // char *p = a;
    // fuh(p);
    // printf("%s",p);
    // printf("%d",read(5));
    int arry[12]={3,3,4,4,4,4,4,5,5,6,6,7};
    int arrz[2];
    int * p = arrz;
    p = searchRange(arry,12,4,arrz);
    printf("\n");
    printf(" %d",p[0]);
    printf(" %d",p[1]);
    return 0;
}