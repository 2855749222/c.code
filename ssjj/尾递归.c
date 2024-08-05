#include <stdio.h>

int rear(int n,int rer)//尾递归 可以优化成循环,节约栈空间的利用
{
    if (n == 0)
    {
        return rer;
    }

    return rear(n-1,rer+n);//不是逆序了 ,顺序累加
    
}
int main()
{
    int sum = rear(5,0);
    printf("%d",sum);
    return 0;
}