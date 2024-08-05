#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reaf(char *s, int len)
{
    if (len <= 1)
    {
        return;
    }

    reaf(s + 1, len - 2);
    char tamp;
    tamp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = tamp;
}

int main()
{
    //1
    int spacenum = 0;
    int linenum = 0;
    int othernum = 0;
    while (1)
    {
        char ch = getchar();
        if(ch == '#')
        {
            break;
        }
        if(ch == ' ')
        {
            spacenum+=1;
        }
        else if (ch == '\n')
        {
            linenum+=1;
        }
        else
        {
            othernum+=1;
        } 


    }
    printf("spacenum:%d\n",spacenum);
    printf("linenum:%d\n",linenum);
    printf("othernum:%d\n",othernum);
    return 0;
    //2
    // char str[15];
    // scanf("%s",str);
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     if (str[0] == 'x')
    //     {
    //         printf("break");
    //         break;
    //     }
        
    //     if(str[i] == 'a' || str[i] == 'A')
    //     {
    //         str[i] = '*';
    //     }
    //     if(str[i] == 'b' || str[i] == 'B')
    //     {
    //         str[i] = '#';
    //     }
    // }
    // printf("\n%s",str);
    //3***
    char *str = (char*)malloc(16*sizeof(char)); // 分配16个字符的空间，包括空字符
    char **strshort = NULL;//定义二级指针
    scanf("%[^#]", str);
    char * p = strtok(str," ");
    int count = 0;
    while (p!=NULL)
    {     
        count++;
        strshort =(char**)realloc(strshort,count*sizeof(char*));//重新分配strshort指针的大小 
        strshort[count-1] = (char*)malloc(strlen(p)+1*sizeof(char));//为子字符串分配内存,+1是给字符串的结束符空间
        strcpy(strshort[count-1],p);//子字符串p,复制给strshort[count-1]
        p = strtok(NULL," ");
    }
    for (int i = 0; i < count; i++)
    {
          printf("%s",strshort[i]);
          free(strshort[i]);
          strshort[i] = NULL;
    }
    free(strshort);
    strshort = NULL;
    free(str);
    str = NULL;
    //4
    // char n[] = "abcde";
    // printf("%s",n);
    // reaf(n,strlen(n));
    // printf("\n%s",n);
    
    
    
}