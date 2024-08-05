#include <stdio.h>
#include <stdlib.h>
typedef int Elemtpye;
//实现 循环 数组双向队列 
typedef struct//队列结构体
{
    Elemtpye *data;//数据指针
    int front;//队列前指针
    int rear;//尾巴
    int quesize;//队列大小
    int queCapacity; // 容量
} DoubleQueue;
DoubleQueue *creatQueue(int Capacity)//队列初始化 ,获取初始容量大小
{
    DoubleQueue *queue = (DoubleQueue *)malloc(sizeof(DoubleQueue));//分配内存空间
    queue->queCapacity = Capacity;//赋值容量
    queue->data = (int *)malloc(Capacity * sizeof(int));//分配数据空间
    queue->quesize = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
int dequeIndex(DoubleQueue *deque, int i) {//!!! 重点 当front入队时 ,结构上是从后往前存放数据 
    // 通过取余操作实现数组首尾相连                     (size = 5) 例如1 2 3 入队 front下标为 2 数组为 N N 3 2 1  
    // 当 i 越过数组尾部时，回到头部                    当rear入队时 ,结构上是从前往后存放数据 
    // 当 i 越过数组头部后，回到尾部                    继上面 插入 4 入队 rear下标为 0 数组 为: 4 N 3 2 1
    //                                                 实际上在遍历时 是从front开始 +1的 所以输出为 3 2 1 4
    return ((i + deque->queCapacity) % deque->queCapacity);//返回 值 + size*size的取余
}
void pushfront(DoubleQueue * que,Elemtpye num)//首入队
{
    if (que->quesize == que->queCapacity)//判断 队列大小 是否等于 容量大小
    {
       printf("队列已满");
       return ;
    }
    que->front = dequeIndex(que,que->front-1);//获取 下标 要符合 循环数组 ,front -1 实际上是为了头插法
    que->data[que->front] = num; //取到下标后赋值
    printf("\n front = %d\n",que->front);
    que->quesize++;//大小++
    
}
void pushrear(DoubleQueue * que,Elemtpye num)//尾入队
{
    if (que->quesize == que->queCapacity)//判断 队列大小 是否等于 容量大小
    {
       printf("队列已满");
       return ;
    }
    
    que->rear = dequeIndex(que,que->front+que->quesize);//获取下标 没有尾插人时 front + 大小 往往等于 容量,后续入队size++
    printf("\n rear = %d",que->rear);
    que->data[que->rear] = num;
    que->quesize++;
    
}
/* 访问队首元素 */
int peekFirst(DoubleQueue *que)
 {
    // 访问异常：双向队列为空
    if (que != NULL)
    {
        return que->data[que->front];//访问front目前所在下标
    }
    else
    {
        return -1;
    }
}

/* 访问队尾元素 */
int peekLast(DoubleQueue *que) 
{
    // 访问异常：双向队列为空
    if (que != NULL)
    {
        int last = dequeIndex(que, que->front + que->quesize - 1);//因为rear在逻辑上是顺序存储的所以需要下标减一
        return que->data[last];
    }
    else
    {
        return -1;
    }
}

/* 队首出队 */
int popFirst(DoubleQueue *que) 
{
    int num = peekFirst(que);//获取队首元素
    // 队首指针向后移动一位
    que->front = dequeIndex(que, que->front + 1);//首地址后移
    printf("\n front = %d\n",que->front);
    que->quesize--;
    return num;
}

/* 队尾出队 */
int popLast(DoubleQueue *deque) 
{
    int num = peekLast(deque);//获取队尾元素
    deque->quesize--;//顺序存储只需要大小自减就行
    return num;
}
void show(DoubleQueue *que) //front遍历
{
    if (que->quesize == 0) {
        printf("队列为空");
        return;
    }
    int i = que->front;//获取首元素下标
    printf("队列元素：");
    for (int j = 0; j < que->quesize; j++) //循环size遍
    {
        printf("%d ", que->data[dequeIndex(que, i)]);//打印当前下标
        i = dequeIndex(que, i + 1);//下标自增
    }
    printf("");
}
int main()
{
    DoubleQueue * que = creatQueue(5);
    pushfront(que,1);
    pushfront(que,2);
    pushrear(que,4);
    pushrear(que,5);
    pushfront(que,111);
    show(que);
    printf("队首出列:%d\n",popFirst(que));
    show(que);
    printf("队尾出列:%d\n",popLast(que));
    show(que);
    pushfront(que,12);
    pushrear(que,13);
    show(que);
    return 0;

}