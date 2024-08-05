#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *creatNode()
{
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
void insertNode(Node **tail, int num)
{
    if (tail == NULL)
    {
        return;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->val = num;
    newNode->next = NULL;
    (*tail)->next = newNode;
    (*tail) = newNode;
}
void showNode(Node *head)
{
    if (head->next == NULL)
    {
        return;
    }
    Node *temp = head->next;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
Node *mergeTowlist(Node *list1, Node *list2)
{
    // 为空情况
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
    // 创建一个哑节点作为合并后链表的头节点
    Node *dummy = malloc(sizeof(Node));
    Node **curr = &dummy;

    // 遍历两个链表，比较节点值，并连接到新链表中
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            (*curr)->next = list1;
            curr = &((*curr)->next);
            list1 = list1->next;
        }
        else
        {
            (*curr)->next = list2;
            curr = &((*curr)->next);
            list2 = list2->next;
        }
    }
    // 处理剩余的元素
    if (list1)
    {
        (*curr)->next = list1;
    }
    if (list2)
    {
        (*curr)->next = list2;
    }

    return dummy->next;
}
Node *sortList(Node *head) //归并排序 时间 O(nlogn) 空间O(1)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *dummyhead = malloc(sizeof(Node));// 新键哑节点指向第一个节点
    dummyhead->next = head;
    int listlen = 0;
    Node *node = head;
    while (node)//获取链表长度
    {
        listlen++;
        node = node->next;
    }
    for (int subLength = 1; subLength < listlen; subLength <<= 1)//用迭代替代递归的作用 从1个开始 两两 拆分 排序 合并 每次成两倍 扩曾
    {
        Node *prev = dummyhead, *curr = dummyhead->next;//用prev 指针用来合并链接拆分链接后的节点 , curr 指针用来分段需要排序的链 两两排序
        while (curr != NULL)//curr 不为空 继续分段
        {
            Node *head1 = curr;//分第一段
            for (int i = 1; i < subLength  && curr && curr->next; i++)//细节一 保证 curr 下一个存在 //否则 移动到空节点了 则下面的语句 curr->next 会报错
            {
                curr = curr->next;
            }

            Node *head2 = curr->next;//获取第二段
            curr->next = NULL;//断开第一段
            curr = head2;//移动到第二段 
            for (int i = 1; i < subLength && curr && curr->next; i++)//保证curr 和 curr下一个存在  存在 否则会报错 使用&& curr && curr->next是良好的编程习惯
            {                                                       //使用&&curr的原因是 如果在前面的运行中curr为空 则curr->next会访问空节点的下一个导致程序崩溃
                curr = curr->next;
            }

            Node *next = NULL;//next 指针 用来保存后续的节点
            if (curr != NULL)
            {
                next = curr->next;
                curr->next = NULL;//断开第二段
            }
            Node *mergelist = mergeTowlist(head1, head2);//将第一段和第二段 合并两段顺序链
            prev->next = mergelist;//用prev键接 排序合并好的顺序链

            while (prev->next)//prev指针移动到链尾
            {
                prev = prev->next;
            }

            curr = next;//获取后续的链继续循环分割
        }
    }
    return dummyhead->next;
}

void main()
{
    Node *head = creatNode();
    Node *tail = head;
    insertNode(&tail, 5);
    insertNode(&tail, 4);
    insertNode(&tail, 3);
    insertNode(&tail, 7);
    insertNode(&tail, 6);
    insertNode(&tail, 1);
    // showNode(head);
    head->next = sortList(head->next);
    showNode(head);
    return;
}