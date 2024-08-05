#include <string.h>
#include <stdio.h>

/* 平方阶（递归实现） */
// int quadraticRecur(int n) {
//     if (n <= 0)
//         return 0;
//     int *nums = malloc(sizeof(int) * n);
//     printf("递归 n = %d 中的 nums 长度 = %d\r\n", n, n);
//     int res = quadraticRecur(n - 1);
//     free(nums);
//     return res;
// }


int mystrcmp(char *a,char *b)
{
    while ((*a!='\0')&&(*a == *b))
    {
        a++;
        b++;
    }
    return a-b;
    
}
int main() {
    char a = "avbn1";
    char b = "avbn";
    int (*a)(int);
    printf("%d",mystrcmp(&a,&b));
    // char str[105] = "hellohellohellohell";
    // printf("Before bzero: %s\n", str);

    // 使用 bzero 将字符串的前 5 个字符设置为 0
    // bzero(str, 5);
    // printf("After bzero: %s\n", str);
    //  printf("%d111\n",quadraticRecur(7));
    // if((8 & (1 << 3)) != 0)
    // {
    //     printf("xxx");
    // }

    return 0;
}
