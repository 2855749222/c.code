#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};
 
 struct ListNode* temp,*newhead,*curr,*end;
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int Listlen = 0;
    temp = head;
    newhead = malloc(sizeof(struct ListNode)); // 哑节点
    newhead->val = 0;
    newhead->next = head;
    while(temp)
    {
        Listlen++;
        temp = temp->next;
    }
    temp = newhead;
    int count = 1;//计数
    curr = newhead->next;
    while(Listlen/k > 0)
    {
        if(count != k)
        {
            end = curr->next;
            curr->next = end->next;
            end->next = newhead->next;
            newhead->next = end;
            count++;
        }
        else
        {
            newhead = curr;//newhead 跳到下一个需要反转链前
            curr = newhead->next;
            count = 1;
            Listlen -= k;
        }
    }
    return temp->next;
}