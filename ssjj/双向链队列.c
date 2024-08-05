#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <deque>
typedef int Elemtype;

typedef struct DoubleListNode//节点结构体
{
    Elemtype data;
    struct DoubleListNode *next;
    struct DoubleListNode *prev;
} DoubleListNode;
DoubleListNode *newdoublListNode(int num) // 构造新节点
{
    DoubleListNode *newNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
typedef struct//队列结构体
{
    struct DoubleListNode *front;
    struct DoubleListNode *rear;
    int quesize;
} DoubleListQueue;
DoubleListQueue *newdoubListQueue() // 构造队列链表
{
    DoubleListQueue *deque = (DoubleListQueue *)malloc(sizeof(DoubleListQueue));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}
void push(DoubleListQueue **deque, int num, bool isFront)//入队 , bool为真 插队,在首位插入front,bool为假 排队,在末尾插入 rear
{
    if ((*deque) == NULL)
    {
        (*deque) = newdoubListQueue();
        return;
    }
    DoubleListNode *newNode = newdoublListNode(num);
    // 若链表为空，则令 front 和 rear 都指向node
    if ((*deque)->front == NULL)
    {
        (*deque)->front = (*deque)->rear = newNode;
        return;
    }
    if (isFront)
    {
        (*deque)->front->prev = newNode;
        newNode->next = (*deque)->front;
        (*deque)->front = newNode;
        printf("插队成功\n");
    }
    else
    {
        (*deque)->rear->next = newNode;
        newNode->prev = (*deque)->rear;
        (*deque)->rear = newNode;
        printf("排队成功\n");
    }
    (*deque)->quesize++;
}
int pop(DoubleListQueue **deque, bool isFront)//出队 , bool为真 插队,在首位出队,bool为假 排队,在末尾出队
{
    if (*deque == NULL)
    {
        printf("队列为空\n");
        return -1;
    }
    int var;
    if (isFront)
    {
        var = (*deque)->front->data;//存放出队的值
        DoubleListNode *temp = (*deque)->front->next;//保存第二个节点
        if (var)//为真 断开 第一个 出队节点 
        {
            temp->prev = NULL;//断开 下一个节点的前驱 重要!
            (*deque)->front->next = NULL;//断开这个节点的后继
        }
        free((*deque)->front);//释放
        (*deque)->front = temp;//移动front 到下一个节点
           
    }
    else
    {
        var = (*deque)->rear->data;
        DoubleListNode *temp = (*deque)->rear->prev;
        if (var)
        {
            temp->next = NULL;
            (*deque)->rear->prev = NULL;
        }
        free((*deque)->rear);
        (*deque)->rear = temp;
    }
    (*deque)->quesize--;
    return var;
}
void show(DoubleListQueue *deque)//遍历节点 头遍历
{
    if (deque == NULL || deque->front == NULL)
    {
        printf("双向链队列为空");
        return;
    }
    DoubleListNode *temp = deque->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("");
}
int main()
{
    DoubleListQueue *deque = newdoubListQueue();
    push(&deque, 1, 1);
    push(&deque, 2, 1);
    push(&deque, 3, 1);
    push(&deque, 4, 1);
    show(deque);
    printf("\n出队%d\n", pop(&deque, 1));
    show(deque);
    printf("\n出队%d\n", pop(&deque, 1));
    show(deque);
    printf("\n");
    push(&deque, 4, 0);
    show(deque);
    printf("\n后出队%d\n", pop(&deque, 0));
    show(deque);
    return 0;
}
