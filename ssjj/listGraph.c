#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef int Elentype;
typedef struct GraphAdjNode // 节点结构体
{
    int vertex;
    struct GraphAdjNode *next;
} GraphAdjNode;

typedef struct GraphAdjlist // 图链结构体
{
    int size;
    GraphAdjNode *heads[MAX_SIZE]; // 存放顶点
} GraphAdjlist;

typedef struct QueueList // 队列结构体 实现 广度优先遍历
{
    Elentype data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;
void printDFS(GraphAdjlist * grlist,Elentype * statuc, int index,GraphAdjNode * ver);
Queue *cearteQueue(); // 初始化队列
void delvertex(GraphAdjlist *grlist, int vertex); // 删除顶点
void printfvertex(GraphAdjlist *grlist, Elentype ver); // 打印 顶点
void delEdge(GraphAdjlist *grlist, Elentype ver1, Elentype ver2);// 删除边
void addEdge(GraphAdjlist *grlist, Elentype ver1, Elentype ver2); // 添加边 i j 为 下标
void insertlist(GraphAdjlist *grlist, int num); // 插入顶点
void printDFS(GraphAdjlist * grlist,Elentype * statuc, int index,GraphAdjNode * ver);//辅助深度遍历
void GraphDFS(GraphAdjlist *grlist);//深度优先遍历
void GraphBFS(GraphAdjlist *grlist, Queue *que,Elentype *BFS); // 广度遍历
void GraphenQueue(GraphAdjlist *grlist, Elentype vernum, Queue *que,int * status); // 图顶点出队  边入队列操作
void enQueue(Queue *que, Elentype vernum,int * status,GraphAdjlist *grlist); //入队  传入 队列和顶点 在 传入 状态 判断是否 入队过
GraphAdjlist *ceartGraphlist(); // 初始化 链图
Queue *cearteQueue() // 初始化队列
{
    Queue *que = (Queue *)malloc(sizeof(Queue));
    que->front = 0;
    que->rear = 0;
    que->size = 0;
    return que;
}
void enQueue(Queue *que, Elentype vernum,int * status,GraphAdjlist *grlist) //入队  传入 队列和顶点 在 传入 状态 判断是否 入队过
{
    int i;
    for (i = 0;i<grlist->size; i++)//查找该顶点的下标
    {
        if (grlist->heads[i]->vertex == vernum)
        {
            //printf("顶点 %d",grlist->heads[i]->vertex);
            break;
        }
    }
    if(status[i] == 1)//判断是否入队过
    {
        printf("已经入队过了\n");
        return;
    }
    status[i] = 1; //更新入队的状态
    if (que->size == MAX_SIZE)
    {
        printf("队列已满\n");
        return;
    }
     printf("入队%d",vernum);
    que->data[que->rear] = vernum;
    que->rear = (que->rear + 1) % MAX_SIZE;
    que->size++;
}
Elentype deQueue(Queue *que) // 出队
{
    if (que->size == 0)
    {
        printf("队列为空\n");
        return 0;
    }
    Elentype num = que->data[que->front];
    que->front = (que->front + 1) % MAX_SIZE;
    que->size--;
    return num;
}
void GraphenQueue(GraphAdjlist *grlist, Elentype vernum, Queue *que,int * status) // 图顶点出队  边入队列操作
{
    
    int i;
    for (i = 0;i<grlist->size; i++)//查找顶点下标
    {
        if (grlist->heads[i]->vertex == vernum)
        {
            printf("顶点 %d",grlist->heads[i]->vertex);
            break;
        }
    }
    if (i == grlist->size)
    {
        printf("无效顶点\n");
        return;
    }
    printf("\n%d下标\n",i);
    
    GraphAdjNode *ver = NULL;
    if (grlist->heads[i]->next!=NULL)
    {
        ver = grlist->heads[i]->next;
        printf("有%d\n",ver->vertex);
    }
   
    // grlist->heads[i]->vertex = -1;
    while (ver)
    {
        
        enQueue(que, ver->vertex,status,grlist);
        ver = ver->next;
    }
    
}
void GraphBFS(GraphAdjlist *grlist, Queue *que,Elentype *BFS) // 广度遍历
{
    int index = 0;
    int indexBFS = 0;//路径下标
    Elentype num = 0;
    Elentype vertexnum = 0;
    int status[MAX_SIZE] = {0};
    while (1)
    {
      
        if (index ==  grlist->size)//判断 下标是否 结束
        {
            printf("结束");
           break;
        }
        printf("\nstatus:%d\n",status[index]);
         if (status[index] == 1)//状态为遍历过 跳过
        {
            index++;
            continue;
        }
        num = grlist->heads[index]->vertex; //获取值
        enQueue(que, num,status,grlist);    //存入队
        vertexnum = deQueue(que);   //获取出队值
       
        for (int i = 0; vertexnum; i++)//出队不为空 ,一直出队
        {
            printf("\nver :%d \n", vertexnum);//遍历
            BFS[indexBFS++] = vertexnum;
            GraphenQueue(grlist, vertexnum, que,status);//出队顶点 将该顶点后继入队 传入 状态
            vertexnum = deQueue(que);//更新出队顶点
        }
        
        index++;
       
        
    }
}
void GraphDFS(GraphAdjlist *grlist)//深度优先遍历
{
    int statuc[MAX_SIZE] = {0}; //顶点状态存储
    int index = 0;
    while(1)
    {
        if (index == grlist->size)
        {
            printf("结束");
            return;
        }
        if (statuc[index] == 1)//判断状态
        {
            index++;

            continue;
        }
        printf("\n");
        printDFS(grlist,statuc,index,grlist->heads[index]);//遍历该顶点 以及后继节点 //传入 图 , 状态 , 下标 , 当前顶点
        index++;
    }
}
void printDFS(GraphAdjlist * grlist,Elentype * statuc, int index,GraphAdjNode * ver)
{
    statuc[index] = 1; //改变该节点状态
    printf("%d ",ver->vertex);//遍历该节点
    GraphAdjNode * temp = ver->next;
    while (temp)//如有后继 继续遍历
    {        
        for (int j = 0; grlist->heads[j]; j++)//循环获取 节点下标
        {
            if (statuc[j] == 1)//判断该节点状态
            {
                continue;
            }
            if (grlist->heads[j]->vertex == temp->vertex) //遍历到该节点
            {
                printDFS( grlist,statuc,j,grlist->heads[j]);//递归实现 深度遍历 
                statuc[j] = 1;//更改节点的状态
                break;
            }     
        }
        temp = temp->next;
    }   
}
GraphAdjlist *ceartGraphlist() // 初始化 链图
{
    GraphAdjlist *grlist = (GraphAdjlist *)malloc(sizeof(GraphAdjlist));
    grlist->size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grlist->heads[i] = NULL; // 初始化为空
    }
    return grlist;
}
void insertlist(GraphAdjlist *grlist, int num) // 插入顶点
{
    if (grlist->size == MAX_SIZE)
    {
        return;
    }
    GraphAdjNode *newNode = (GraphAdjNode *)malloc(sizeof(GraphAdjNode)); // 新建节点
    newNode->vertex = num;
    newNode->next = NULL;
    grlist->heads[grlist->size] = newNode; // 赋值给对应下标
    grlist->size++;
}
void addEdge(GraphAdjlist *grlist, Elentype ver1, Elentype ver2) // 添加边 i j 为 下标
{
    int i = 0 ;
    int j = 0;
    for ( i = 0; grlist->heads[i]; i++) //获取第一个顶点的下标
    {
        if (grlist->heads[i]->vertex == ver1)
        {
            break;
        }
        
    }
    for ( j = 0; grlist->heads[j]; j++)//获取第二`个顶点的下标
    {
        if (grlist->heads[j]->vertex == ver2)
        {
            break;
        }
        
    }
    if (i == grlist->size || j == grlist->size)
    {
        printf("顶点不存在");
        return;
    }
    
    GraphAdjNode *tamp = (GraphAdjNode *)malloc(sizeof(GraphAdjNode)); // 建立新节点
    tamp->vertex = grlist->heads[i]->vertex;                           // 获取链接节点值
    // 头插入
    tamp->next = grlist->heads[j]->next;
    grlist->heads[j]->next = tamp;

    GraphAdjNode *tampl = (GraphAdjNode *)malloc(sizeof(GraphAdjNode));
    tampl->vertex = grlist->heads[j]->vertex;
    tampl->next = grlist->heads[i]->next;
    grlist->heads[i]->next = tampl;
}
void delEdge(GraphAdjlist *grlist, Elentype ver1, Elentype ver2) // 删除边
{
    int i = 0 ;
    int j = 0;
    for ( i = 0; grlist->heads[i]; i++) //获取第一个顶点的下标
    {
        if (grlist->heads[i]->vertex == ver1)
        {
            break;
        }
        
    }
    for ( j = 0; grlist->heads[j]; j++)//获取第二`个顶点的下标
    {
        if (grlist->heads[j]->vertex == ver2)
        {
            break;
        }
        
    }
    if (i == grlist->size || j == grlist->size)
    {
        printf("顶点不存在");
        return;
    }
    int del = grlist->heads[i]->vertex; // 获取删除值
    GraphAdjNode *head = grlist->heads[j];

    while (head)
    {
        if (head->next->vertex == del) // 判断下一个是否等与 因为单链表 不可以  head = head->next 操作 因为会断链
        {
            GraphAdjNode *tamp = head->next;
            head->next = head->next->next; // 这里一定不可以 head = head->next 因为会段链 上一个节点的next无法识别到 下下个节点
            free(tamp);
            break;
        }
        head = head->next;
    }

    del = grlist->heads[j]->vertex;
    head = grlist->heads[i];
    while (head)
    {
        if (head->next->vertex == del)
        {
            GraphAdjNode *tamp = head->next;
            head->next = head->next->next;
            free(tamp);
            break;
        }
        head = head->next;
    }
}
void printfvertex(GraphAdjlist *grlist, Elentype ver) // 打印 顶点
{
    int i = 0 ;
    for ( i = 0; grlist->heads[i]; i++) //获取第一个顶点的下标
    {
        if (grlist->heads[i]->vertex == ver)
        {
            break;
        }
        
    }
    if (i == grlist->size)
    {
        printf("顶点不存在");
        return;
    }
    GraphAdjNode *tamp = grlist->heads[i];
    while (tamp)
    {
        printf("%d ", tamp->vertex);
        tamp = tamp->next;
    }
}
void delvertex(GraphAdjlist *grlist, int vertex) // 删除顶点
{
    int i;
    for (i = 0; grlist->heads[i]; i++) //获取下标
    {
        if (grlist->heads[i]->vertex == vertex)
        {
            break;
        }
    }
    if (i == grlist->size)
    {
        printf("值不存在");
        return;
    }
    GraphAdjNode *head = grlist->heads[i];
    GraphAdjNode *tamp = NULL;
    while (head->next)
    {
        tamp = head->next;
        head->next = head->next->next;
        free(tamp);
    }
    for (int j = i; j < grlist->size - 1; j++)
    {
        grlist->heads[j] = grlist->heads[j + 1];
    }
    printf("删除成功");
    grlist->size--;
}
void main()
{
    Elentype BFS[MAX_SIZE] = {0};//广度遍历 最短路径
    GraphAdjlist *grlist = ceartGraphlist();
    insertlist(grlist, 11); // 插入顶点
    insertlist(grlist, 22);
    insertlist(grlist, 33);
    insertlist(grlist, 66);// 插入顶点
    insertlist(grlist, 55);
    insertlist(grlist, 44);
    addEdge(grlist, 11, 66); // 链接 
    addEdge(grlist, 66, 55); // 链接 
    addEdge(grlist, 66, 22); // 链接 
    addEdge(grlist, 22, 44); // 链接

    addEdge(grlist, 33, 55); // 链接 
    //这里需要 先删除顶点的边
    // delEdge(grlist,33,22); // 删除 
    // delEdge(grlist,66,22);
    // delEdge(grlist,44,22);
    // delvertex(grlist, 22);   // 删除 22 //szie -1 

    printf("\n广度遍历:\n");
    Queue * que = cearteQueue();//辅助队列
    GraphBFS(grlist,que,BFS);
    printf("\n最短路径为:\n");
    for (int i = 0; BFS[i] != 0; i++)
    {
        printf("%d ",BFS[i]);
    }
    
    printf("\n深度遍历:\n");
    GraphDFS(grlist);//深度遍历
    // printfvertex(grlist,66);
}