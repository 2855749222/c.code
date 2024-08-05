#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef int Elemtype;//声明为int 类型
typedef struct stackNode//节点结构体
{
    Elemtype Data;
    struct stackNode *next;
} stacklink;
struct stackNode *newNode, *tempNode;

stacklink *_init_stack_()//初始化栈
{
    newNode = (stacklink *)malloc(sizeof(stacklink));
    newNode->next = NULL;
    return newNode;
}
void _push_stack_(stacklink *top, Elemtype num)//入栈
{
    newNode = (stacklink *)malloc(sizeof(stacklink));
    newNode->Data = num;
    newNode->next = top->next;//逻辑为 : 每次入栈 插入top 节点后 top->next节点前 连接后一个节点
    top->next = newNode;//前面连接top
    printf("入栈成功\n");
}
Elemtype _pop_stack_(stacklink *top)//出栈
{
    if (top->next == NULL)
    {
        printf("栈为空\n");
        return -1;
    }
    tempNode = top->next;//出栈取栈头,也就是top-next
    Elemtype denum = tempNode->Data;
    top->next = tempNode->next;//移动栈头,到下一个节点
    free(tempNode);
    tempNode = NULL;
    return denum;
}
void _RPN_stacklink_(stacklink *stack, char *token)//求后缀表达式
{
    char *tokens = token;
    Elemtype numb1 = 0, numb2 = 0, count = 0;
    for (int i = 0; i < strlen(tokens); i++)
    {
        if (isdigit(tokens[i]))//isdigit为判断字符是否为int ,是int返回真
        {
            _push_stack_(stack, (Elemtype)tokens[i] - '0');//将字符转成Elemtypet 入栈
            printf("入栈:%c", tokens[i]);
            continue;
        }
        if (tokens[i] == '+')
        {
            printf("执行:%c", tokens[i]);
            numb1 = _pop_stack_(stack);
            numb2 = _pop_stack_(stack);
            count = numb1 + numb2;
            _push_stack_(stack, count);
        }
        else if (tokens[i] == '-')
        {
            printf("执行:%c", tokens[i]);
            numb1 = _pop_stack_(stack);
            numb2 = _pop_stack_(stack);
            count = numb1 - numb2;
            _push_stack_(stack, count);
        }
        else if (tokens[i] == '*')
        {
            printf("执行:%c", tokens[i]);
            numb1 = _pop_stack_(stack);
            numb2 = _pop_stack_(stack);
            count = numb1 * numb2;
            _push_stack_(stack, count);
        }
        else if (tokens[i] == '/')
        {
            printf("执行:%c", tokens[i]);
            numb1 = _pop_stack_(stack);
            numb2 = _pop_stack_(stack);
            count = numb1 / numb2;
            _push_stack_(stack, count);
        }
    }
    printf("值为:%d", _pop_stack_(stack));
}
int main()
{

    char tokens[100];
    printf("\n请输入正确的后缀表达式:");
    scanf("%s",tokens);
    stacklink *stack = _init_stack_();
    _RPN_stacklink_(stack, tokens);
    return 0;
}