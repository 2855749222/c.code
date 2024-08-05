#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *temp, *head, *tail, *newNode;
void creatLine() // 链表初始化
{

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    tail = head;
}
void addNode(int num) // 尾插入
{
    if (head->next == NULL)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;
        newNode->prev = head;
        head->next = newNode;
        return;
    }
    temp = head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;
}

void insertNode(int index, int num)
{
    if (head->next == NULL)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;
        newNode->prev = head;
        head->next = newNode;
        printf("列表为空，已放入第一个\n");
        return;
    }
    temp = head->next;
    int eindex = 1;
    while (temp->next != NULL && eindex < index)
    {
        temp = temp->next;
        eindex++;
    }
    if (eindex == index)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    else
    {
        printf("index 输入错误");
        return;
    }
}
void delNode(int index)
{
    if (head->next == NULL)
    {
        printf("空链表\n");
        return;
    }
    temp = head->next;
    int eindex = 1;
    while (temp->next != NULL && eindex < index)
    {
        temp = temp->next;
        eindex++;
    }
    if (eindex == index)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    else
    {
        printf("index 输入错误");
        return;
    }
}
void findNode(int index)
{
    if (head->next == NULL)
    {
        printf("空链表\n");
        return;
    }
    temp = head->next;
    int eindex = 1;
     while (temp->next != NULL && eindex < index)
    {
        temp = temp->next;
        eindex++;
    }
    if (eindex == index)
    {
        printf("第%d个为 ：%d",index,temp->data);
    }
    else
    {
        printf("index 输入错误");
        return;
    }
}

  
void reverseline()
{
    // 如果链表为空，则直接返回
    if (head->next == NULL)
    {
        printf("空链表");
        return;
    }
    // 初始化两个指针，current指向当前节点，temp用于交换节点的前后指针
    Node *current = head, *temp = NULL;
    // 遍历整个链表
    while (current != NULL)
    {
        // 将当前节点的前驱指针存储到temp中
        temp = current->prev;
        // 交换当前节点的前后指针
        current->prev = current->next;
        current->next = temp;
        // 移动current指针到下一个节点（实际上是前一个节点）
        current = current->prev;
    }
    // 如果temp不为空，说明链表不为空，更新头节点
    if (temp != NULL)
    {
        head = temp->prev; // 更新头节点为原链表的尾节点
    }
}




void show()
{
    if (head->next == NULL)
    {
        return;
    }
    temp = head->next;
    printf("\n链表为： ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}
int main()
{
    creatLine();
    addNode(11);
    addNode(12);
    addNode(13);
    addNode(14);
    insertNode(2, 2);
    show();
    delNode(2);
    show();
    findNode(3);
    reverseline();
    show();

}