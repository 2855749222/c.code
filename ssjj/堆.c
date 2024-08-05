#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
typedef struct heap //堆结构体
{
    int *data;
    int size;
} Heap;
void siftup(Heap *heap, int i); //自下而上
void siftDown(Heap *heap, int i);//自顶向下
void insertheap(Heap *heap, int num, int size)//插入
{
    heap->data[heap->size++] = num;
    siftup(heap, heap->size - 1);
}
int popheap(Heap *heap)//堆顶出
{
    int pop = heap->data[0];//保存堆顶数据
    heap->data[0] = heap->data[heap->size - 1];//交换最后叶子节点
    heap->size--;
    siftDown(heap, 0);//开始自顶向下
    return pop;
}
void temp(Heap *heap, int i, int j)//交换数据
{
    int temp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = temp;
}
void siftDown(Heap *heap, int i)//自顶向下
{
    while (1)
    {

        int left = i * 2 + 1;//获取左子节点
        int right = left + 1;//获取右子节点
        int max = i;
        //判断各节点大小
        if (left < heap->size && heap->data[left] > heap->data[max])
        {
            max = left;
        }
        if (right < heap->size && heap->data[right] > heap->data[max])
        {
            max = right;
        }
        if (max == i)
        {
            break;
        }
        temp(heap,i,max);
        i = max;
    }
}

void siftup(Heap *heap, int i)//自下向上
{
    while (1)
    {

        if (i / 2 < 0 || heap->data[i / 2] >= heap->data[i])//到顶或小于父节点
        {
            return;
        }
        int temp = heap->data[i / 2];
        heap->data[i / 2] = heap->data[i];
        heap->data[i] = temp;
        i = i / 2;
    }
}
void showHeap(Heap *heap)//遍历树 层次遍历
{
    if (heap == NULL)
    {
        return;
    }

    for (int i = 0; i < heap->size; i++)
    {
        printf(" %d ", heap->data[i]);
    }
}
int main()
{
    int array[10] = {2, 6, 4, 8, 9, 10, 11, 1, 13, 5};
    Heap *heap;
    heap->size = 0;
    heap->data = (int *)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        insertheap(heap, array[i], SIZE);
    }
    // printf("%d");
    showHeap(heap);
    printf("\n");
    printf("出堆%d",popheap(heap));
    printf("\n");
    showHeap(heap);
    printf("出堆%d",popheap(heap));
    printf("\n");
    showHeap(heap);
    return 0;
}