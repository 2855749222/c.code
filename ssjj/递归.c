#include <stdio.h>
#include <string.h>
int sum=1;
void f(int n)
{
    if(n<1)
    {
        return ;
    }
    f(n-1);
    printf("%d\n",n);

    
}
void revert(char *s,int len)
{
    //找到一个可以返回的条件
    if(len<=1)
    {
        return ;
    }

    //递归自己调用自己
    revert(s+1,len-2);

    //解决剩下的问题
    char temp;
    temp = s[0];
    s[0] = s[len-1];
    s[len-1] = temp;
}
int fact(int N)
{
    
   if(N == 0 || N == 1)
   {
    return 1;
   }
   else
   {
    return N*fact(N-1);
   }
}

//斐波那契数列 0 1 1 2 3 5 8 13 21...
int fib(int n)
{
    if (n == 1 || n == 2)// 终止条件 f(1) = 0, f(2) = 1
    {
        return n-1;
    }
    
    int res = fib(n-1) + fib(n-2); // 递归调用 f(n) = f(n-1) + f(n-2)
    
    return res; // 返回结果 f(n)
}
int main()
{
    int i = 10;
    char s[] = "abcdef";
    revert(s,strlen(s));
    printf("%s",s);
    // printf("%d\n",fact(5));
    // int m;   
    // int a,k = m = 4,*p1=&k,*p2=&m;
    // a= p1 == p2;
    // printf("%d",a);
    return 0;
}