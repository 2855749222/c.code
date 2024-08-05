#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int *arr;        // 数组 ,存储列表元素
    int capacity;    // 列表容量
    int size;        // 列表大小
    int extandRatio; // 列表扩容倍数
} Mylist;

Mylist *newMylist()
{
    Mylist *nums = (Mylist *)malloc(sizeof(Mylist));
    nums->capacity = 10;
    nums->arr = (int *)malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extandRatio = 2;
}

void delMylist(Mylist *nums) // 释放列表
{
    free(nums->arr);
    free(nums);
}

int getsize(Mylist *nums) // 获取列表长度
{
    return nums->size;
}

int getcapacity(Mylist *nums) // 获取列表容量
{
    return nums->capacity;
}

int get(Mylist *nums, int index) // 获取对应下标数据
{
    assert(index < nums->size != 0 && index >= 0);
    return nums->arr[index];
}

void set(Mylist *nums, int index, int num) // 更新下标对应数据
{
    assert(index < nums->size && index >= 0);
    nums->arr[index] = num;
}

void extendcapacity(Mylist *nums) // 扩容数组
{
    int newCapacity = getcapacity(nums) * nums->extandRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;
    for (int i = 0; i < nums->size; i++)
    {
        extend[i] = temp[i];
    }

    free(temp);
    nums->capacity = newCapacity;
    nums->arr = extend;
}

void add(Mylist *nums, int num) // 在尾部add数据
{
    if (getsize(nums) == getcapacity(nums))
    {
        extendcapacity(nums);
    }
    nums->arr[nums->size] = num;
    nums->size++;
}

void insert(Mylist *nums, int index, int num) // 中间插入数据
{
    assert(index >= 0 && index < nums->size);
    if (getsize(nums) == getcapacity(nums))
    {
        extendcapacity(nums);
    }
    for (int i = getsize(nums); i > index; i--)
    {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size++;
}

void removeItem(Mylist *nums, int index)
{
    assert(index >= 0 && index < getsize(nums));

    for (int i = index; i <= getsize(nums); i++)
    {
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size--;
}

void show(Mylist *nums)
{
    if (getsize(nums) == 0)
    {
        printf("列表为空\n");
        return;
    }
    for (int i = 0; i < nums->size; i++)
    {
        printf("%d ", nums->arr[i]);
    }
}
/* 将列表转换为 数组用于打印 */
int *toArray(Mylist *nums)
{
    return nums->arr; // 返回指向数组的指针，可用于打印或其他操作
}

int main()
{
    Mylist *mylist = newMylist();                       // 创建一个新的列表对象
    add(mylist, 1);                                     // 添加元素 1
    add(mylist, 2);                                     // 添加元素 2
    add(mylist, 3);                                     // 添加元素 3
    add(mylist, 1);                                     // 添加元素 1
    add(mylist, 2);                                     // 添加元素 2
    add(mylist, 3);                                     // 添加元素 3
    add(mylist, 1);                                     // 添加元素 1
    add(mylist, 2);                                     // 添加元素 2
    add(mylist, 3);                                     // 添加元素 3
    add(mylist, 1);                                     // 添加元素 1
    add(mylist, 2);                                     // 添加元素 2
    add(mylist, 3);                                     // 添加元素 3
    insert(mylist, 1, 4);                               // 在索引 1 处插入元素 4
    removeItem(mylist, 2);                              // 移除索引为 2 的元素
    printf("Size: %d\n", getsize(mylist));              // 输出列表的大小
    printf("Capacity: %d\n", getcapacity(mylist));      // 输出列表的容量
    printf("Element at index 1: %d\n", get(mylist, 1)); // 输出索引为 1 的元素值
    show(mylist);
    delMylist(mylist); // 销毁列表对象
    return 1;
}