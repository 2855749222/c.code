#include <stdio.h>
#include <stdlib.h>
void _create_line_();
void _prin_line_();
void _find_line_(int fin);
void _insert_line_();
void _inserthead_line(int posi, int numb);
void _insertposition_line(int posi, int numb);
void _del_line_();
// 定义链表节点结构体
struct Node
{
    int data;          // 节点数据
    struct Node *next; // 指向下一个节点的指针
};

struct Node *head, *newNode, *deil; // 定义头节点、新节点和尾节点指针

// 创建链表函数
void _create_line_()
{
    head = (struct Node *)malloc(sizeof(struct Node)); // 分配头节点内存
    deil = head;                                       // 初始化尾节点为头节点
    int num;
    printf("请输入链表数据 -1 为结束符：");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node)); // 分配新节点内存
        newNode->data = num;                                  // 设置新节点数据
        newNode->next = NULL;                                 // 新节点的下一个节点设为空
        deil->next = newNode;                                 // 将新节点添加到链表尾部
        deil = newNode;                                       // 更新尾节点为新节点
        scanf("%d", &num);                                    // 读取下一个节点数据
    }
}

// 遍历链表函数
void _prin_line_()
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    struct Node *temp = head->next; // 从头节点的下一个节点开始遍历
    printf("列表为：");
    while (temp != NULL)
    {
        printf("%d ", temp->data); // 打印节点数据
        temp = temp->next;         // 移动到下一个节点
    }
    free(temp);  // 释放临时节点内存
    temp = NULL; // 将临时节点指针设为空
}

// 查找链表中指定位置的节点值
void _find_line_(int fin)
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    int index = 1;
    struct Node *tamp = head->next; // 从头节点的下一个节点开始查找
    while (1)
    {
        if (tamp == NULL)
        {
            printf("超过链表长度");
            break;
        }

        if (index == fin)
        {
            printf("第%d位值为：%d", fin, tamp->data);
            break;
        }
        tamp = tamp->next; // 移动到下一个节点
        index++;           // 更新索引值
    }
}

// 插入数据到链表中
void _insert_line_()
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    _prin_line_(); // 打印当前链表
    int posi, numb;
    printf("请输入需要插入的位置(后插入 0为在链首插入):");
    scanf("%d", &posi);
    printf("请输入需要插入数：");
    scanf("%d", &numb);
    if (posi == 0) // 判断是否是插入第一个数
    {
        _inserthead_line(posi, numb); // 调用插入头节点函数
    }
    else
    {
        _insertposition_line(posi, numb); // 调用插入指定位置节点函数
    }
}

// 插入数据到链表头部
void _inserthead_line(int posi, int numb)
{
    newNode = (struct Node *)malloc(sizeof(struct Node)); // 分配新节点内存
    newNode->data = numb;                                 // 设置新节点数据
    newNode->next = head->next;                           // 新节点的下一个节点设为原头节点的下一个节点
    head->next = newNode;                                 // 将新节点设置为头节点的下一个节点
    _prin_line_();                                        // 打印更新后的链表
}

// 插入数据到链表指定位置
void _insertposition_line(int posi, int numb)
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    struct Node *temp = head->next; // 从头节点的下一个节点开始查找插入位置
    int index = 1;
    while (index < posi)
    {
        temp = temp->next; // 移动到下一个节点
        index++;           // 更新索引值
    }
    if (temp == NULL)
    {
        printf("插入位置超过链表...");
        return;
    }
    else
    {
        newNode = (struct Node *)malloc(sizeof(struct Node)); // 分配新节点内存
        newNode->data = numb;                                 // 设置新节点数据
        newNode->next = temp->next;                           // 新节点的下一个节点设为原节点的下一个节点
        temp->next = newNode;                                 // 将新节点插入到原节点后面
    }
    _prin_line_(); // 打印更新后的链表
}

// 删除链表中指定位置的节点
void _del_line_()
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    int posi;
    printf("需要删除的位：");
    scanf("%d", &posi);
    int index = 1;
    if (posi == 1) // 判断是否是删除头节点
    {
        newNode = head->next;          // 保存头节点的下一个节点
        head->next = head->next->next; // 将头节点的下一个节点设为原头节点的下一个节点的下一个节点
        free(newNode);                 // 释放原头节点内存
        newNode = NULL;                // 将新节点指针设为空
        _prin_line_();                 // 打印更新后的链表
        return;
    }
    struct Node *temp = head->next; // 从头节点的下一个节点开始查找删除位置
    while (index < posi - 1)
    {
        temp = temp->next; // 移动到下一个节点
        index++;           // 更新索引值
    }
    if (temp == NULL)
    {
        printf("删除位置超过链表...");
        return;
    }
    else
    {
        newNode = temp->next;          // 保存要删除的节点
        temp->next = temp->next->next; // 将要删除节点的前一个节点的下一个节点设为要删除节点的下一个节点
        free(newNode);                 // 释放要删除节点内存
        newNode = NULL;                // 将新节点指针设为空
    }
    _prin_line_(); // 打印更新后的链表
}
void _reverse_line_fun1_() // 实现链表反转 原地反转法 beg 不动 //  链 掉 接 移 四步搞定
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    printf("链表反转,原地反转法\n");
    struct Node *beg = head->next;
    struct Node *end = head->next->next;
    while (end)
    {
        beg->next = end->next;//链接end下一个节点，防止丢失
        end->next = head->next;//将end调换到头指针下一个,next头指针下一个
        head->next = end;//链接 头指针
        end = beg->next;//移动 end 到bed的下一个开始新一轮调换
    }
    _prin_line_();
}
void _reverse_line_fun2_()//实现链表反转  头插法
{
    if (head == NULL)
    {
        printf("请创建列表");
        return;
    }
    printf("链表反转,头插法\n");
    struct Node *p = head->next;
    struct Node *q ;
    head->next = NULL;
    while (p)
    {
        q = p->next;//保存p的后续链接，不会断掉
        p->next = head->next;//头插法 将p连接到到head的后继
        head->next = p;//链接head 和 p
        p = q;//移动p 到 后继节点
    }
    _prin_line_();
}
// 释放链表内存并清空链表头指针
void _free_line_()
{
    if (head == NULL)
    {
        printf("链表为空，无需释放内存");
        return;
    }
    struct Node *temp = head; // 从头节点开始释放内存 
    while (temp != NULL)
    {
        struct Node *nextNode = temp->next; // 保存下一个节点指针
        free(temp);                         // 释放当前节点内存
        temp = NULL;                        // 将当前节点指针设为空
        temp = nextNode;                    // 移动到下一个节点
    }
    head = NULL; // 将链表头指针设为空，表示链表已清空
    printf("链表内存已释放");
}

int main()
{
    int i = 0;
    while (i < 50) // 限制循环次数，避免无限循环导致程序卡死或崩溃
    {
        int sel;
        printf("选着需要的功能：");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            _create_line_(); // 创建链表功能选项
            break;
        case 2:
            _prin_line_(); // 打印链表功能选项
            break;
        case 3:
            _find_line_(3); // 查找链表中指定位置的节点值功能选项，这里假设查找第3个位置的值作为示例。可以根据实际需求修改。
            break;
        case 4:
            _insert_line_(); // 插入数据到链表中功能选项
            break;
        case 5:
            _del_line_(); // 删除链表中指定位置的节点功能选项
            break;
        case 6:
            _free_line_(); // 释放链表内存并清空链表头指针功能选项
            break;
        case 7:
            _reverse_line_fun1_();// 实现链表反转 原地反转法 beg 不动 //  链 掉 接 移 四步搞定
            break; 
        case 8:
            _reverse_line_fun2_();// 实现链表反转
            break; 
        case 0:
            return 0;
        }
        i++; // 更新循环计数器，避免无限循环导致程序卡死或崩溃。可以根据实际需求修改。
    }
}