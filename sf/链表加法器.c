#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;
typedef struct list
{
    int count;
    struct Node *head;
    struct Node *tail;
} list;

void creatlist(list *p, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = n;
    newNode->next = NULL;
    p->tail->next = newNode;
    p->tail = newNode;
}
Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    Node *list1 = l1;
    Node *list2 = l2;
    Node *ret1 = l1;
    Node *ret2 = l2;
    int sum = 0;
    int count = 0;
    while(list1 != NULL && list2 != NULL)//遍历两链表 判读那个更短
    {   
        list1 = list1->next;
        list2 = list2->next;
    }
    if(list1 == NULL)
    {
        while(l1 != NULL)//l1 短 将 l1 加给l2
        {
            sum = l2->val+l1->val+count;//加计数器
            l2->val = sum % 10;//取模
            if(sum >= 10)//大于10进步1
            {
                count = 1;
            }
            else
            {
                count = 0;
            }
            if(l1->next == NULL) //返回
            {break;}
            l1=l1->next;
            l2=l2->next;
        }
       
        while(count == 1 && l2->next !=NULL)//判断是否有进步 且l2还有后继
        {
            l2 = l2->next;
            int sum = l2->val+1;
            if( sum>= 10)
            {
                count = 1;
            }
             else
            {
                 count = 0;
            }
            l2->val =  sum%10;
           
        }
        if(count == 1)//还存在进步 则新建节点加到尾部
        {
            struct Node *new = (Node *)malloc(sizeof(Node ));
            new->val = 1;
            new->next = NULL;
            l2->next = new;
        }   
        return ret2;
    }
    else
    {
        while(l2 != NULL)
        {
            sum = l1->val+l2->val+count;
            l1->val = sum % 10;
            if(sum >= 10)
            {
                count = 1;
            }
            else
            {
                count = 0;
            }
            if(l2->next ==NULL)
            {break;}
            l1=l1->next;
            l2=l2->next;
        }
         while(count == 1 && l1->next !=NULL)
        {
            l1 = l1->next;
            int sum = l1->val+1;
            if(sum >= 10)
            {
                count = 1;
            }
            else
            {
                 count = 0;
            }
            l1->val =  sum%10;     
        }
        if(count == 1)
        {
            Node *new1 = (Node *)malloc(sizeof(Node ));
            new1->val = 1;
            new1->next = NULL;
            l1->next = new1;
        } 
        return ret1;
    }
    
    
}

void main()
{
    list *p = (list *)malloc(sizeof(list));
    p->head = (Node *)malloc(sizeof(Node));
    p->tail = p->head;
    creatlist(p, 2);
    creatlist(p, 2);
    creatlist(p, 2);

    list *p2 = (list *)malloc(sizeof(list));
    p2->head = (Node *)malloc(sizeof(Node));
    p2->tail = p2->head;
    creatlist(p2, 3);
    creatlist(p2, 3);
    creatlist(p2, 3);
}