#include <stdio.h>
#include <stdlib.h>
void _create_doubleline_();
void _prin_doubleline_();
void _insert_doubleline_();
void _del_doubleline_();
void _free_doubleline_();
void _find_doubleline_();
struct Node
{
    int data;
    struct Node *next;
    struct Node *prefix;
};
struct Node *head, *tail, *tamp, *newNode;
void _create_doubleline_()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->prefix = NULL;
    head->next = NULL;
    tail = head;
    int num;
    printf("\n请输入链表数据 -1 为结束符:");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;
        newNode->prefix = tail;
        tail->next = newNode;
        tail = newNode;
        scanf("%d", &num);
      
    }
    tamp = (struct Node *)malloc(sizeof(struct Node));
    tamp->next = NULL;
    tamp->prefix = tail;
    tail->next = tamp;
    tail = tamp;
}
void _free_doubleline_()
{
    if (head == NULL) //判读链表是否为空
    {
        printf("链表为空，无需释放内存");
        return;
    }
    while (head != NULL)
    {
        tamp = head->next;
        free(head);
        head = NULL;
        head = tamp;
    }
    
    printf("链表内存已释放");
}
void _prin_doubleline_()
{
    if (head == NULL)
    {
        printf("\n请创建列表");
        return;
    }
    tamp = head->next;
    while (tamp != NULL && tamp != tail)
    {
        printf("%d ", tamp->data);
        tamp = tamp->next;
    }
   
}
void _find_doubleline_(int fin)
{
    if (head == NULL)
    {
        printf("\n请创建列表");
        return;
    }
    tamp = head->next;
    int index = 1;
    while (index < fin)
    {
        if (tamp == NULL)
        {
           printf("长度超过链表");
           return;
        }
        tamp = tamp->next;
        index++;
    }
    printf("\n第%d个为:%d",fin,tamp->data);
}
void _insert_doubleline_()
{
     if (head == NULL)
    {
        printf("\n请创建列表");
        return;
    }
    int posi,numb;
    printf("\n选择需要插入的位置:");
    scanf("%d",&posi);
    printf("\n需要插入的值:");
    scanf("%d",&numb);
    int index = 1;
    tamp = head->next;
    while (index < posi)
    {
        tamp = tamp->next; // 移动到下一个节点
        index++;           // 更新索引值
    }
    printf("%d",tamp->data);
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = numb;

    newNode->next = tamp;//newNode后继指针指向要插入的位置的节点
    newNode->prefix = tamp->prefix;//newNode前驱指针指向要插入的位置的节点的前一个节点

    tamp->prefix->next = newNode;//连接要插入的位置的节点的前一个节点的后继
    tamp->prefix = newNode;//再连接插入的位置的节点的前驱节点
    printf("\n插入成功");
    
}
void _del_doubleline_()
{   
     if (head == NULL)
    {
        printf("\n请创建列表");
        return;
    }
    int index = 1;
    int del;
    printf("\n输入需要删除第几位:");
    scanf("%d",&del);
    tamp = head->next;
    while (index < del)
    {
        if(tamp == NULL)
        {
            printf("\n超过链表长度");
            return ;
        }
        tamp = tamp->next;
        index++;
    }
    tamp->next->prefix = tamp->prefix;//连接删除节点后一个节点的前驱节点为删除点的前驱
    tamp->prefix->next = tamp->next;//连接删除点前驱节点的后驱为删除节点的后驱
    free(tamp);
    tamp = NULL;
    printf("删除成功");
}       
int main()
{
    int i = 0;
    while (i < 50)
    {
        int sel;
        printf("\n选着需要的功能:");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            _create_doubleline_();
            break;
        case 2:
            _prin_doubleline_();
            break;
        case 3:
            _find_doubleline_(4);
            break;
        case 4:
            _insert_doubleline_();
            break;
        case 5:
            _del_doubleline_();
            break;
        case 6:
            _free_doubleline_();
           break;   
        case 7:
            return 0;
            
        }
        i++;
    }
}