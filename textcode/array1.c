#include <stdio.h>
#include <string.h>
#include <math.h>
void chtoal(char ch)
{
    if (!(ch >= 'A' && ch <= 'Z'))
    {
        return;
    }
    
    int cen = ch - 'A' + 1;

    for (int i = 0; i < cen; i++)
    {
        for (int j = (cen - i ) ; j>0 ; j--)
        {
            printf(" ");
        }

        char one = 'A';
        for (int j = 0; j < (i+1) * 2-1; j++)
        {

            if (j <= i)
            {
                one='A'+j;
                printf("%c", one);
            }
            else
            {
                one--;
                printf("%c", one);
           
            }
           
        }
        printf("\n");
    }
}
int main()
{
    // 1
    // int count[10];
    // int max = 0;
    // int min = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     scanf("%d", &count[i]);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", count[i]);
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = i; j < 10; j++)
    //     {

    //         if (count[i] < count[j])
    //         {
    //            int tamp;
    //            tamp = count[j];
    //            count[j] = count[i];
    //            count[i] = tamp;
    //         }
    //     }
    //     break;
    // }
    // max = count[0];
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = i; j < 10; j++)
    //     {

    //         if (count[i] > count[j])
    //         {
    //            int tamp;
    //            tamp = count[j];
    //            count[j] = count[i];
    //            count[i] = tamp;
    //         }
    //     }
    //     break;
    // }
    // min = count[0];
    // printf("\nmax:%d\n", max);
    // printf("min:%d\n", min);
    //2金字塔
    char ch;
    scanf("%c",&ch);
    chtoal(ch);
    // 3 字符数量
    // int spacenum = 0;
    // int wordnum = 0;
    // int othernum = 0;
    // while (1)
    // {
    //     char ch = getchar();
    //     if(ch=='#')
    //     {
    //         break;
    //     }
    //     if(ch == ' ')
    //     {
    //         spacenum+=1;
    //     }
    //     else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    //     {
    //         wordnum+=1;
    //     }
    //     else
    //     {
    //         othernum+=1;
    //     }

    // }
    // printf("spacenum:%d",spacenum);
    // printf("wordnum:%d",wordnum);
    // printf("othernum:%d",othernum);
    // 4 去重
    // char str[32] = {'\0'};
    // scanf("%s", str);
    // char shortstr[32];
    // memset(shortstr,0,32);// 将数组的前32个字符设置为0
    // int N = 0;
    // for(int i =0; i<strlen(str);i++)
    // {

    //     for (int j = 0; j < N+1; j++)
    //     {

    //         if(str[i] == shortstr[j])
    //         {
    //         //printf("break!");
    //             N--;
    //             break;
    //         }
    //        // printf("%d",j);
    //         if(N<=j)
    //         {
    //             shortstr[N] = str[i];
    //         }

    //     }
    //     N++;
    // }
    // printf("shortstr:%s",shortstr);
    // 两数之和
    // int nums[] = {8,0,5,7,2};
    // int target = 9;
    // for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    // {
    //    for (int j = 0; j < sizeof(nums) / sizeof(nums[0]);j++)
    //    {
    //         if(i == j)
    //         {
    //             continue;;
    //         }
    //         if(nums[i]+nums[j] == 9)
    //         {
    //             printf("%d,%d",i,j);
    //             return 1;
    //         }
    //    }
    // }
    // 两数相加
    // int a[] = {9,9,9,9,9,9,9};
    // int b[] = {9,9,9,9};
    // int num1, num2, sum;
    // num1 = num2 = sum = 0;
    // for (int i = sizeof(a) / sizeof(a[0]) - 1; i >= 0; i--)
    // {
    //     num1 += a[i] * pow(10, i);
    // }
    // for (int i = sizeof(b) / sizeof(b[0]) - 1; i >= 0; i--)
    // {
    //     num2 += b[i] * pow(10, i);
    // }
    // sum = num1 + num2;
    // int count = 0;
    // if (sum == 0)
    // {
    //     count = 1;
    // }
    // else
    // {
    //     while (sum != 0)
    //     {
    //         sum /= 10;
    //         count++;
    //     }
    // }
    // sum = num1 + num2;
    // for (int i = 1; i < count + 1; i++)
    // {
    //     printf("%d ", sum%10);
    //     sum /= 10;
    // }
}
