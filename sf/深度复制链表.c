#include <stdlib.h>  
  
struct Node {  
    int val;  
    struct Node *next;  
    struct Node *random;  
};  
  
struct Node* copyRandomList(struct Node* head) {  
    if (head == NULL) {  
        return NULL;  
    }  
  
    // 第一步：复制每个节点并插入到原始节点的后面  
    for (struct Node *node = head; node != NULL; node = node->next->next) {  
        struct Node *newnode = malloc(sizeof(struct Node));  
        newnode->val = node->val;  
        newnode->random = NULL;  
        newnode->next = node->next;  
        node->next = newnode;  
    }  
  
    // 第二步：设置复制节点的random指针  
    for (struct Node *node = head; node != NULL; node = node->next->next) {  
        if (node->random != NULL) {  
            node->next->random = node->random->next;  
        }  
    }  
  
    // 第三步：分离原始链表和复制链表  
    struct Node *dummy = malloc(sizeof(struct Node)); // 创建一个哑节点作为新链表的头  
    dummy->next = NULL;  
    struct Node **tail = &dummy->next; // 尾指针，用于构建新链表  
  
    for (struct Node *node = head; node != NULL; node = node->next) {  
        struct Node *copy = node->next; // 复制节点  
        node->next = copy->next; // 恢复原始链表的next指针  
  
        if (copy->next != NULL) {  
            copy->next = copy->next->next; // 分离复制节点的next指针  
        }  
  
        *tail = copy; // 将复制节点添加到新链表中  
        tail = &((*tail)->next); // 更新尾指针  
    }  
  
    struct Node *headNew = dummy->next; // 新链表的真正头节点  
    free(dummy); // 释放哑节点  
  
    return headNew;  
}