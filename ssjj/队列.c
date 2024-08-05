#include <stdio.h>
#include <stdlib.h>
//循环队列
//可以循环利用空间,但是循环队列为空或满时,front和rear指向的位置都是一样的
//解决方法有两个
//1. 在定义结构体或者分配空间设置size大小时,预留一个元素位来存放rear的指向,判断后续加一取模判读队列是否满了
//2.给定一个计数器 ,入队加一 ,出队减一,当等于size时为队满,等于0时队空
typedef struct Queue
{
    int *Data;
    int front;
    int rear;
    int size;
} Queue;
Queue *_init_Queue_(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->Data = (int *)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size+1;//这里是为了保留一个元素位,来判断后续,rear+1判断队列是否满
}
int _isEmpty_Queue_(Queue *queue)//判段空
{
    return queue->rear == queue->front;
}
int _isFull_Queue_(Queue *queue)//判断满
{
    return (queue->rear + 1) % queue->size == queue->front;//判断queue->rear是否到达预留空间 +1 取模等于front 说明队满
}
void _enqueue_(Queue *queue, int num)//入队
{
    if (_isFull_Queue_(queue))
    {
        printf("队列已满!");
        return;
    }
    queue->Data[queue->rear] = num;
    queue->rear = (queue->rear + 1) % queue->size;//每次入队后 队尾加一取模
}
int _dequeue_(Queue *queue)
{
    if (_isEmpty_Queue_(queue))
    {
        printf("队列为空!!");
        return 0;
    }
    return queue->Data[(queue->front++) % queue->size];//每次出队后front加一取模
}
int _getFront_(Queue *queue)
{
    if (_isEmpty_Queue_(queue))
    {
        printf("队列为空!!");
        return 0;
    }
    return queue->Data[(queue->front) % queue->size];//取队首
}
void _destroy_Queue_(Queue *queue)//销毁队列
{
    free(queue->Data);
    queue->Data = NULL;
    free(queue);
    queue = NULL;
    printf("销毁成功!!");
}
int main()
{

    struct Queue *queue = _init_Queue_(3);
    _enqueue_(queue, 11);
    _enqueue_(queue, 12);
    _enqueue_(queue, 13);
  
    printf("第一个%d\n", _dequeue_(queue));
    printf("第二个%d\n", _dequeue_(queue));
    printf("第三个%d\n", _dequeue_(queue));
    _enqueue_(queue, 14);
    _enqueue_(queue, 15);
    _enqueue_(queue, 16);
 
    printf("当前队首为%d\n", _getFront_(queue));
    printf("第4个%d\n", _dequeue_(queue));
    printf("第5个%d\n", _dequeue_(queue));
    printf("第6个%d\n", _dequeue_(queue));
    _destroy_Queue_(queue);
    return 0;
}