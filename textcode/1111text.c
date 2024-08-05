#include <stdio.h>
#include <string.h>
#include <math.h>
void revert(char *s,int len)
{
    //找到一个可以返回的条件
    if(len ==1 || len == 0)
    {
        return ;
    }

    //递归自己调用自己
  

    //解决剩下的问题
    char temp;
    temp = s[0];
    s[0] = s[len-1];
    s[len-1] = temp;

    return revert(s+1,len-2);
}
int main()
{
    // char str1[10] = {0}; 
    // char str2[10] = "hellozou";
    // char *p;
    // printf("%d\n",strlen(str2));
    // p = strchr(str2,'z');
    // printf("%s\n",p);
    // strcpy(str1,str2);
    // printf("%s\n",str1);
    // char ch [100];
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%c",&ch[i]);
    //     while (getchar()!='\n')
    //     {
    //     }
        
    // }
    // printf("%s", ch);
    char str[10];
    char str2[10];
    memset(str,0,10);
    int i = 0;
    int j = 0;
    while (1)
    {
        str[i] = getchar();
        if (str[i] == '\n')
        {
            break;
        }
        i++;
    }
    while (1)
    {
        str2[j] = getchar();
        if (str[j] == '\n')
        {
            break;
        }
        i++;
    }
    int n,m;
    for (n = 0; n < strlen(str); n++);
    n++;
    for (int m = 0; m < strlen(str2); m++)
    {
        str[n+m] = str2[m];
    }
    
    
    printf("%s\n",str2);
    return 0;
}
           