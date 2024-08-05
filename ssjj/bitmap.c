#include <stdlib.h>
#include <stdio.h>

typedef struct Bitmap//创建bitmap结构体
{
    int size;           //定义的是字节大小
    unsigned char *bits;//内部位
} Bitmap;

Bitmap *creatmap(int maxsize)//初始化位图
{
    Bitmap *bitmap = (Bitmap *)malloc(sizeof(Bitmap));//建立位图指针
    bitmap->size = (maxsize + 7) / 8;//向上取整 一个字节8位 可以表示8个元素 +7 需要向上取整, 得出的size就是bits的下标
    bitmap->bits = (unsigned char *)calloc(bitmap->size, sizeof(unsigned char));//分配size个字节大小的bits 
    return bitmap;                                                              //calloc 分配后每个位默认为0
}                                                                               //unsigned 无符号方便位运算
void insertmap_and_sort(Bitmap *bitmap, int *array, int size) // 传入 位图,插入数组,数组大小,数组最大值
{
    int index = 0;
    int byte_index = 0;
    int bit_index = 0;
    for (int i = 0; i < size; i++)//存入数据 用位 1来表示
    {
        index = array[i];//存入的数据 作为 第几个位的位数 所以需要 取整 取余 来位运算到 bits中
        printf("array:%d  ", array[i]);
        byte_index = index / 8; // 获取对应字节 ,bits下标
        printf("byte:%d  ", byte_index);
        bit_index = index % 8; // 获取字节中位的位置
        printf("bit:%d  \n", bit_index);
        bitmap->bits[byte_index] |= (1 << bit_index); // 位运算 将对应bit设置为1  字节 位下标为 0~7
    }
    int j = 0;
    index = 0;
    int i = 0;
    while (index < size) //将bits中排序好的存放到 数组中
    {
        if ((bitmap->bits[i] & (1 << j)) != 0) //判读 位数是否不为 0 说明 保护数据 数据就是位的实际位置 从0开始
        {
            array[index] = i * 8 + j; //i位 实际bits下标 , j 为 字节中的第几位 所以需要i*8 + j来表示 位的位置
            printf("i:%d",i);
            printf("j:%d\n", j);
            index++;//数组下标自增
        }
        if (j == 7) //判段 字节下标j是否满了, 满了清零j ,bits下标i++
        {
            j = 0;
            i++;
            continue;//跳出当前循环 不执行下面j++
        }
        j++;
    }

}
int findmap(Bitmap *bitmap,int num)// 查找值是否存在
{
    int type_index = num / 8;
    int bit_index = num % 8;
    if ((bitmap->bits[type_index] & (1<<bit_index))  != 0)//不为0 说明 该位置为1 找到了
    {
        return num;
    }
    return 0;
    
}
int main()
{
    int array[10] = {7, 8, 9, 1, 2, 4, 5, 11, 40, 17};//建立数组
    Bitmap *bitmap = creatmap(40);//初始化位图 实参是 数组的最大值
    insertmap_and_sort(bitmap, array, 10);//存入数据 后获取数组 ,实现排序 O(N)
    for (int i = 0; i < 10; i++)//打印排序好的数组
    {
        printf("%d ", array[i]);
    }
    printf("\n查找 11 返回%d ", findmap(bitmap,11));
    printf("\n查找 3 返回%d ", findmap(bitmap,3));
    free(bitmap->bits);
    free(bitmap);
    return 0;
}