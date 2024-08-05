#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count ;
    scanf("%d",&count);
    int m ,i;
    int abss = abs(count);//存放count的决定值
    char X0num [10];//定义存放16进制的字符数组
    bzero(X0num,10);//初始化为0,好赋值
    for ( i = 0; abss != 0 &&i < 10; i++)
    {
       m = abss%16;//取余得出第n位16进制
       switch (m)
       {
       case 0 ... 9 :
            X0num[i] = '0'+ m; //将整型转为字符型 '0'+7 ='7'
            break;
       
       case 10 ... 15 :
            X0num[i] = 'A'+ m-10;
            break;
       }
        abss = abss/16;//取整后进入循环
    }
    printf("%c0x",count>=0?'\b':'-');//判断原数是否为负数
    for ( i--; i >=0 ; i--)//反向遍历数组
    {
        printf("%c",X0num[i]);
    }
    
    return 0;
}