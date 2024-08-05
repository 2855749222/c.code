#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *data;
    int top;
    int size;
} stack;
stack *_init_stack_(int size);
int _isEmpty_(stack *stack);
int _isFull_(stack *stack);
void _push_stack_(stack *stack, int num);
int _pop_stack_(stack *stack);
void _del_stack_(stack *stack);

stack *_init_stack_(int size)//初始化栈, 返回该栈类型
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->data = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}
int _isEmpty_(stack *stack)//判断栈是否为空
{
    return  stack->top == -1;  
   
}
int _isFull_(stack *stack)//判断栈是否满了
{
    if (stack->top == stack->size - 1)
    {
        return 0;
    }
}
void _push_stack_(stack *stack, int num)//入栈操作
{
    if (!_isFull_(stack))
    {
        printf("栈已满!!!");
        return;
    }
    stack->data[++stack->top] = num;
}
int _pop_stack_(stack *stack)//出栈操作
{
    if (_isEmpty_(stack))
    {
        printf("栈为空!!!");
        return 0;
    }
    return stack->data[stack->top--];
}
void _del_stack_(stack *stack)//销毁栈
{
    if (_isEmpty_(stack))
    {
        printf("栈为空!!!");
        return;
    }
    free(stack->data);
    stack->data = NULL;
    free(stack);
    stack = NULL;
    printf("销栈成功!!!");
}
int _peek_stack_(stack *stack)//查看栈顶元素
{
    if (_isEmpty_(stack))
    {
        printf("栈为空!!!");
        return 0;
    }
    return stack->data[stack->top];
}
int main()
{
    stack *stack = _init_stack_(5);
    _push_stack_(stack, 1);
    _push_stack_(stack, 2);
    _push_stack_(stack, 3);
    _push_stack_(stack, 3);
    printf("栈顶元素：%d\n", _peek_stack_(stack)); // 输出：3
    printf("出栈元素：%d\n", _pop_stack_(stack));  // 输出：3
    printf("栈顶元素：%d\n", _peek_stack_(stack)); // 输出：2
    printf("出栈元素：%d\n", _pop_stack_(stack));  // 输出：2
    printf("出栈元素：%d\n", _pop_stack_(stack));  // 输出：1
    _del_stack_(stack);
    return 0;
}