#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
       char *p = "sheraaaa";
       char z[10];
       char m[6];
       strcpy(z,p);
       strncpy(m,p,5);
       // int a = strlen(p);
       if(strcmp(z,m) == 0)
       {
               printf("一样\n");
       }
       else 
       {
              printf("不一样\n");
       }
        if(strncmp(z,m,4) == 0)
       {
               printf("一样\n");
       }
       else 
       {
              printf("不一样\n");
       }
       printf("%s\n",z);
       printf("%s1111111\n",m);
       char ch[] = "http://www.baidu.com";
       char *str = strtok(ch,":/.");
       do
       {
              
              printf("%s",str);
       }while(str = strtok(NULL,":/."));
       
       
       
       return 0 ;
}