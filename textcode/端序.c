#include <stdio.h>

int main()
{
    // int a = 0x12345678; // 使用16进制来测试 端序 这里有四个字节 12 34 56 78 从第一个开始遍历 78是第一个就是小端序 12是第一个则是大端序


    // printf("%hhx\n",    *  (char*)&a    );//  这里取a的地址,再将它强转成 char*型指针,因为char是一个字节 再用 * 解引用,
    //                                  //因为这里有四个字节 所以需要加 hh 一半的一半:1/4 来遍历第一个字节是是多少  遍历12为大端序 遍历78为小端序
    // printf("%hhx",    *  ((char*)&a +2 )   );//可以看到让地址加2就能遍历 34 来证明准确
    // unsigned char a = 'a';
    // printf("%05u",a);
    int a , b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a=%d,b=%d",a,b);
    return 0;
}