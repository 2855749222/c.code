#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;

typedef struct QNode //节点结构体,每个节点包含一个数据域和一个指针域。数据域用于存储队列中的元素，指针域用于链接到下一个节点。
{
    Elemtype Date;
    struct QNode *next;
}QNode;
struct QNode *newNode ,*tempNode;//声明插入节,替换节点
typedef struct LinkQueue//队列结构体,链队列建立 维护了队列的头指针和尾指针,分别指向队列的首节点和末节点。
{   
    QNode *front , *rear;
}LinkQueue;

LinkQueue * _init_linkQunue()//队列初始化
{
    LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));//链队列指针内存分配
    newNode = (QNode*)malloc(sizeof(QNode));//节点内存分配
    Q->front = Q->rear = newNode;//设置头尾指针指向空节点
    Q->rear->next = NULL;
    return Q;
}

void _enlinkQueue_(LinkQueue * Q,Elemtype num)//入队
{
    newNode = (QNode*)malloc(sizeof(QNode));//新节点内存分配
    newNode->Date = num;
    newNode->next = NULL;
    Q->rear->next = newNode;//将尾指针点下一个节点设置为新节点
    Q->rear = newNode;//尾指针向后定位到新节点
    printf("插入成功\n");
}

int _delinkQueue_(LinkQueue *Q)//出队
{
    if (Q->front == Q->rear)
    {
       printf("队列为空!");
        return 0;
    }
    int denum;
    tempNode = Q->front->next;//获取头指针的下一个节点(数据实际存放位置)
    denum = tempNode->Date;//获取当前节点的数值
    Q->front->next = tempNode->next;//连接当前节点的下一个节点到头节点
    free(tempNode);//释放当前节点
    tempNode = NULL;
    if (Q->front->next == NULL)//判断头节点下一个节点是否为空
    {
        Q->front = Q->rear;//为空取尾指针值,回调指针指向
    }
    return denum;//返回出队的值
}

void _showQueue_(LinkQueue *Q)//打印队列
{
     if (Q->front == Q->rear)
    {
       printf("队列为空!");
       return;
    }
    tempNode = Q->front->next ;//取头指针下一个节点(第一个节点)
    printf("队列为:");
    while(tempNode!=NULL)//判断是否为空
    {
        printf("%d ",tempNode->Date);
        tempNode = tempNode->next;//节点自增
    }
}
int main()
{
    LinkQueue *Q = _init_linkQunue();
    _enlinkQueue_(Q,11);
    _enlinkQueue_(Q,12);
    _enlinkQueue_(Q,13);
    _showQueue_(Q);
    printf("第1个数为:%d",_delinkQueue_(Q));
    _showQueue_(Q);
    _enlinkQueue_(Q,14);
     _showQueue_(Q);
    return 0;
}