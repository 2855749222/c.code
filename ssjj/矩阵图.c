#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
#define MAX_SIZE 5
typedef struct  //创建 矩阵图结构体
{
    Elemtype vertice[MAX_SIZE]; //顶点 数组
    Elemtype adjMat[MAX_SIZE][MAX_SIZE];// 矩阵图 表示边连接 二维数组表示
    Elemtype size ;//记录 顶点个数
}GraphAdjMat;

GraphAdjMat * creatGraph()//初始化结构体
{
    GraphAdjMat * graph = (GraphAdjMat*)malloc(sizeof(GraphAdjMat));
    graph->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) // 初始化矩阵图为 0
    {
        for (int j = 0; j< MAX_SIZE; j++)
        {
            graph->adjMat[i][j] = 0; 
        }
        
    }
    return graph;
}

void insertVertice(GraphAdjMat * graph,Elemtype vert)//添加顶点 
{
    if (graph->size == MAX_SIZE)
    {
        printf(" 超过最大值");
        return;
    }
    graph->vertice[graph->size] = vert; //赋值顶点
    graph->size++;
}

void delVertice(GraphAdjMat * graph,Elemtype vert)//删除顶点
{
    int i;
    for ( i = 0; i < graph->size; i++) //查找需要删除的顶点下标
    {
        if(graph->vertice[i] == vert)
        {
            break;
        }
    }
    if (i == graph->size)  
    {
        printf("没有该节点\n");
        return;
    }
    int index = i;
    for (int j = index; j < graph->size-1; j++) //移动该节点后的顶点数组
    {
        graph->vertice[j] = graph->vertice[j+1];
    }
    //十字删除
    for (int i = index; i < graph->size-1 ; i++) //删除一整行
    {
        for (int j = 0; j < graph->size-1; j++)
        {
            graph->adjMat[i][j] = graph->adjMat[i+1][j];
        } 
    }

    for (int i = 0; i < graph->size-1 ; i++)//删除一整列
    {
        for (int j = index; j < graph->size-1; j++)
        {
            graph->adjMat[i][j] = graph->adjMat[i][j+1];
        } 
    }
    graph->size--;//大小减一
    
}

void addEdge(GraphAdjMat * graph,int i ,int j) //添加边 i,j 为下标 表示第i+1 个顶点 和 第j+1 个顶点 相连
{
    if (i < 0 || j < 0 || j > graph->size || i > graph->size || i == j)
    {
        printf("边索引越界或相等\n");  
        return;
    }
    graph->adjMat[i][j] = 1;
    graph->adjMat[j][i] = 1;

}

void removeEdge(GraphAdjMat * graph,int i ,int j)//删除边 i,j 为下标 表示 第i+1 个顶点 和 第j+1 个顶点 
{
    if (i < 0 || j < 0 || j > graph->size || i > graph->size || i == j)
    {
        printf("边索引越界或相等\n");  
        return;
    }
    graph->adjMat[i][j] = 0;
    graph->adjMat[j][i] = 0;

}
 void printGraph(GraphAdjMat * graph)//遍历图
 {
    printf("顶点:\n");
    for (int i = 0; i < graph->size; i++)//遍历顶点
    {
        printf("%d ",graph->vertice[i]);
    }
    printf("\n");
    printf("边:\n"); 
    for (int i = 0; i < graph->size; i++)//遍历边
    {
        for (int j = 0; j <  graph->size; j++)
        {
           printf("%d ",graph->adjMat[i][j]);
        }
        printf("\n");
    }
    
 }

 void main()
 {
    GraphAdjMat * graph = creatGraph();
    Elemtype str[MAX_SIZE] = {1,2,3,4,5};
    for (int i = 0; i < MAX_SIZE; i++)//加入顶点
    {
        printf("%d",str[i]);
        insertVertice(graph,str[i]);
    }
   
    addEdge(graph,0,1);//添加边
    addEdge(graph,2,3);
    addEdge(graph,1,2);
    printGraph(graph);
    printf("删除顶点 4 \n");
    delVertice(graph,4);
    printGraph(graph);
    printf("删除顶边 0-1 \n");
    removeEdge(graph,0,1);
    printGraph(graph);
    printf("删除顶点 5 \n");
    delVertice(graph,5);
    printGraph(graph);
 }