#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void bzero1(char *s, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         s[i] = '\0';
//     }

//     printf("%d", size);
// }
// void memset1(char *s, char ch, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         s[i] = ch;
//     }
// }
// void strcat1(char *str1, char *str2)
// {
//     int i;
//     for (i = 0; str1[i]; i++)
//     {
//     }
//     int j;
//     for (j = 0; str2[j]; j++)
//     {
//         str1[i + j] = str2[j];
//     }
//     // str1[i + j] = '\0';
// }

// char *strstr1(char *str1, char *str2)
// {
//     int i;
//     int j = 0;
//     for ( i = 0; i < str1[i]; i++)
//     {
//         if (str1[i] != str2[j])
//         {
//             continue;;
//         }
//         else
//         {
//             j = 0;
//             while (str2[j])
//             {
//                 if (str1[i] != str2[j])
//                 {
//                     break;
//                 }
//                 j++;
//             }
//             if (!str2[j])
//             {
//                 return &str1[i];
//             }

//         }
//     }
// }

// int strlen1(char * str)
// {
//     int i;
//     for ( i = 0; str[i]; i++);
//     return i;
// }
// int strcmp1(const char *str1, const char *str2)
// {
//     int num1 = 0;
//     int num2 = 0;
//     for (int i = 0; str1[i]; i++)
//     {
//         num1 += str1[i];
//     }
//     printf("%d ",num1);
//     for (int i = 0; str2[i]; i++)
//     {
//         num2 += str2[i];
//     }
//     printf("%d ",num2);
//     return num1 - num2;
// }
char * zipstring(char *str)
{
    int m = 0;
    int i = 0;
    int num = 0;
    static char str1[100] = {0};
    while (str[i])
    {
        if (str[m] == str[i])
        {
            num++;
        }
        else
        {
            if (num > 1)
            {
                char count_str[10];            
                sprintf(count_str, "%d", num); 
                strcat(str1, count_str);       
            }
            char p[10];
            sprintf(p, "%c", str[i - 1]);
            strcat(str1, p);
            m = i;
            i--;
            num = 0;
        }
        i++;
    }
    if (num > 1)
    {
        char count_str[10];           
        sprintf(count_str, "%d", num); 
        strcat(str1, count_str);       
    }
    char p[10];
    sprintf(p, "%c", str[i - 1]);
    strcat(str1, p);
    if (strcmp(str1,str))
    {
        return str1;
    }
    else
    {
         return str;
    } 
}
int main()
{
    // 1
    //  char str[10] = "hello";
    //  printf("\n%s ",str);
    //  bzero1(str,sizeof(str));
    //  printf("\n%s ",str);
    // 2
    //    char str[10] = "hello";
    //     memset1(str, 'A', sizeof(str)-1); // 注意这里使用了sizeof(str) - 1
    //     printf("%s ", str);
    // 3
    // char str[15] = "hello";
    // char str1[15] = " world";
    // strcat1(str,str1);
    // printf("%s ",str);
    // 4
    // char str[15] = "hello";
    // char str1[15] = "ll";
    // char *p = strstr1(str, str1);
    // printf("%s",p);
    // 5
    // char str[15] = "hello";
    // int num = strlen1(str);
    // printf("%d",num);
    // 6
    // char str1[15] = "zzzz";
    // char str2[15] = "zzzz";
    // int num = strcmp1(str1,str2);
    // printf("%d",num);
    // 7
    char str1[100] = "aaaabbvcc";
    char * p = zipstring(str1);
    printf(" %s",p);
    return 0;
}