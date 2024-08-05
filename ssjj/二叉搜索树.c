#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct Node
{
    int data;           // 节点存储的数据
    struct Node *left;  // 左子节点指针
    struct Node *right; // 右子节点指针
} Node;

Node *temp, *newNode; // 全局变量，用于插入操作和遍历操作

// 定义二叉树结构体
typedef struct
{
    Node *root; // 根节点指针
} Tree;

typedef struct Queue // 队列链表 方便 层序遍历
{
    Node * node;
    struct Queue *next;
}Queue;
// 向二叉搜索树中插入一个新的节点
void insertTree(Node **root, int num) // 获取二级指针,因为传入的是tree.root,一级指针递归是无法影响到实际根节点的变动的
{
    newNode = (Node *)malloc(sizeof(Node)); // 分配新节点内存空间
    newNode->data = num;                    // 设置新节点的数据
    newNode->left = NULL;                   // 初始化左子节点为空
    newNode->right = NULL;                  // 初始化右子节点为空

    if (*root == NULL) // 如果根节点为空，直接将新节点作为根节点
    {
        *root = newNode;
        return;
    }

    temp = *root; // 临时变量指向根节点

    // 根据二叉搜索树的性质，将新节点插入到合适的位置
    if (num < temp->data) // 如果新节点的值小于当前节点的值，递归插入左子树
    {
        insertTree(&(*root)->left, num); // 将*root的地址传递,正确的更新根节点
    }
    else if (num > temp->data) // 如果新节点的值大于当前节点的值，递归插入右子树
    {
        insertTree(&(*root)->right, num);
    }
    else if (num == temp->data) // 如果新节点的值等于当前节点的值，不允许插入相同值的节点
    {
        printf("不能输入相同值");
        return;
    }
}

//层序遍历(广度优先搜索)
void levelOrdertree(Node * root)//使用队列链表 实现
{
    if (root == NULL)//判断树为空
    {
        printf("树为空");
        return ;
    }
    Queue * front = (Queue *)malloc(sizeof(Queue));//建立 队列 front 和 rear
    front->next = NULL;
    front->node = root;
    Queue * rear = front; 
    while (front != NULL) //为空跳出循环
    {
        Queue * frequ = front;//保存当前节点
        temp = front->node;//存放 node树节点
        printf("%d ",temp->data);//遍历节点
        if (temp->left != NULL)//判断树节点是否有子节点
        {
            Queue * qutemp = (Queue *)malloc(sizeof(Queue));//建立新节点存放 树节点
            qutemp->next = NULL;
            qutemp->node = temp->left;
            rear->next = qutemp;//链接到尾节点
            rear = qutemp;//移动尾节点
        }
        if (temp->right != NULL)//判断树节点是否有子节点
        {
            Queue * qutemp = (Queue *)malloc(sizeof(Queue));//建立新节点存放 树节点
            qutemp->next = NULL;
            qutemp->node = temp->right;
            rear->next = qutemp;//链接到尾节点
            rear = qutemp;//移动尾节点
        }
        front = front->next;//移动头节点
        free(frequ);//释放保存的节点
        frequ = NULL;
        
    }   
    
}
// 先序遍历二叉树
void proshow(Node *ndoe)
{
    if (ndoe == NULL) // 如果节点为空，返回
    {
        return;
    }

    printf("%d ", ndoe->data); // 访问当前节点
    proshow(ndoe->left);       // 递归遍历左子树
    proshow(ndoe->right);      // 递归遍历右子树
}

// 中序遍历二叉树
void modshow(Node *ndoe)
{
    if (ndoe == NULL) // 如果节点为空，返回
    {
        return;
    }

    modshow(ndoe->left);       // 递归遍历左子树
    printf("%d ", ndoe->data); // 访问当前节点
    modshow(ndoe->right);      // 递归遍历右子树
}

// 后序遍历二叉树
void lastshow(Node *ndoe)
{
    if (ndoe == NULL) // 如果节点为空，返回
    {
        return;
    }

    lastshow(ndoe->left);      // 递归遍历左子树
    lastshow(ndoe->right);     // 递归遍历右子树
    printf("%d ", ndoe->data); // 访问当前节点
}

// 获取二叉树的高度
int get_hight_(Node *node)
{
    if (node == NULL) // 如果节点为空，返回0
    {
        return 0;
    }
    else
    {
        int left_h = get_hight_(node->left);   // 递归计算左子树的高度
        int right_h = get_hight_(node->right); // 递归计算右子树的高度
        int max = left_h;                      // 初始化最大高度为左子树的高度
        if (left_h < right_h)                  // 如果右子树的高度大于左子树的高度，更新最大高度
        {
            max = right_h;
        }
        return max + 1; // 返回最大高度加1（包括当前节点）
    }
}

// 获取二叉树的最大值
int get_MAxnum(Node *node)
{
    if (node == NULL) // 如果节点为空，返回-1表示不存在最大值
    {
        return -1;
    }
    else
    {
        int left_num = get_MAxnum(node->left);   // 递归获取左子树的最大值
        int right_num = get_MAxnum(node->right); // 递归获取右子树的最大值
        int nude = node->data;                   // 当前节点的值
        int max = left_num;                      // 初始化最大值为左子树的最大值
        if (right_num > max)                     // 如果右子树的最大值大于当前最大值，更新最大值
        {
            max = right_num;
        }
        if (nude > max) // 如果当前节点的值大于当前最大值，更新最大值
        {
            max = nude;
        }
        return max; // 返回最大值
    }
}

// 在二叉树中查找指定值的节点
void find_Tree(Node *node, int find)
{
    if (node != NULL) // 如果节点不为空，继续查找
    {
        if (find == node->data) // 如果找到目标值，输出并返回
        {
            printf("\n存在 值为：%d", node->data);
            return;
        }
        else // 如果目标值不在当前节点，根据二叉搜索树的性质，向左或向右子树查找
        {
            if (find < node->data)
            {
                find_Tree(node->left, find);
            }
            else
            {
                find_Tree(node->right, find);
            }
        }
    }
    else if (node == NULL) // 如果节点为空，说明查找失败，输出提示信息
    {
        printf("\n查找值不存在！");
    }
}
Node *findMin(Node *node)//获取最小节点
{
    if (node == NULL)
    {
        return NULL;
    }
    while (node->left != NULL)//找到最左边的节点
    {
        node = node->left;
    }
    return node;//返回改节点
}
// 删除二叉树
Node *deleteTree(Node **node, int num)//相当复杂做好准备
{

    if (*node == NULL)//递归返回值
    {
        printf("NULL");
        return NULL;
    }
    //printf("data:%d", (*node)->data);
    if (num < (*node)->data) //判断值与当前节点
    {
        (*node)->left = deleteTree(&(*node)->left, num);//小于向左边递归
    }
    else if (num > (*node)->data)
    {
        (*node)->right = deleteTree(&(*node)->right, num);//大于向右递归
    }
    else if (num == (*node)->data)//相等执行删除操作
    {
        if ((*node)->right == NULL && (*node)->left == NULL)//第一种情况,需要删除的节点为叶子节点
        {
            Node *temp = *node;//取当前节点
            free(temp);//释放
            temp = NULL;
            *node = NULL;//返回
        }
        else if ((*node)->right && (*node)->left == NULL)//第二种情况,节点有一个子节点,左节点或者右节点
        {
            Node *temp = *node;
            *node = (*node)->right;//获取子节点
            free(temp);//释放该节点
        }
        else if ((*node)->right == NULL && (*node)->left)//第二种情况,节点有一个子节点,左节点或者右节点
        {
            Node *temp = *node;
            *node = (*node)->left;//获取子节点
            free(temp);//释放该节点
        }
        else//第三种情况,节点有两个子节点
        {
            Node *minValueNode = findMin((*node)->right); //调用函数获取右边树的最小节点
            (*node)->data = minValueNode->data;//将获取到的最小节点的值 赋值 给该节点的值
            (*node)->right = deleteTree(&(*node)->right, minValueNode->data);//递归右子树,删除最小节点
            //这里实际上是将需要删除节点的值 替换为 右子树(大的子树)的最小结的值,在删除掉那个最小节点,实际上是交换数据,并没有删除该节点,这样做不会破坏搜索树的结构
        }
    }
    return *node;//返回定位的节点
}

int main()
{
    Tree tree;        // 创建二叉树对象
    tree.root = NULL; // 初始化根节点为空
    int str[7] = {6, 3, 8, 2, 5, 1, 7};
    for (int i = 0; i < 7; i++)
    {
        insertTree(&tree.root, str[i]); // 调用插入函数插入数值到二叉搜索树中 需要用到二级指针
    }
    printf("\n层序遍历：");
    levelOrdertree(tree.root);
    printf("\n先序遍历：");                      // 输出先序遍历结果
    proshow(tree.root);                        // 调用先序遍历函数进行遍历并输出结果
    printf("\n中序遍历：");                    // 输出中序遍历结果
    modshow(tree.root);                        // 调用中序遍历函数进行遍历并输出结果
    printf("\n后序遍历：");                    // 输出后序遍历结果
    lastshow(tree.root);                       // 调用后序遍历函数进行遍历并输出结果
    int h = get_hight_(tree.root);             // 获取二叉树的高度并赋值给变量h
    printf("\n数的度为：%d", h);               // 输出二叉树的高度
    printf("\nmax:%d", get_MAxnum(tree.root)); // 输出二叉树的最大值并赋值给变量max，然后输出该值
    find_Tree(tree.root, 7);                   // 查找值为1的节点并输出结果
    find_Tree(tree.root, 9);                   // 查找值为9的节点并输出结果（不存在）
    deleteTree(&tree.root, 6);
    printf("\n中序遍历：");
    modshow(tree.root);
   
    return 0;
}