#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count = 1;
typedef struct Node//构造节点
{
    int data;
    struct Node *left;
    struct Node *right;
    int hight;
} Node;
typedef struct Tree//构造树节点
{
    Node *root;
} Tree;
Node *crearteNode(int num)//新建节点
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->hight = 0;
    return newNode;
}
int gethight(Node *node)//获取节点高度
{
    if (node == NULL)
    {
        return 0;
    }

    return node->hight;
}
int getBalance(Node *node)//获取平衡因子 判断那种失衡
{
    if (node == NULL)
    {
        return 0;
    }
    return gethight(node->left) - gethight(node->right);
}
Node *leftrotate(Node *root)//左旋
{

    if (root == NULL || root->right == NULL)
    {
        return NULL;
    }
    Node *temp = root->right->left;//如果存在右子树存在左子树,保存         //1,当前节点的右子树作为新树的根节点
    Node *newroot = root->right;//赋值新树根节点为当前节点的右子树            //2, 当前节点作为新根节点的左子树
    newroot->left = root;//当前节点作为新根节点的左子树
    root->right = temp;//新的树根原来有左子树,就作为旧根节点的右子树
    // 更新老树高
    if (gethight((root)->left) > gethight((root)->right))
    {
        (root)->hight = 1 + gethight((root)->left);
    }
    else if (gethight((root)->left) < gethight((root)->right))
    {
        (root)->hight = 1 + gethight((root)->right);
    }
    else
    {
        (root)->hight = 1 + gethight((root)->left);
    }
    // 更新新树高度
    if (gethight(newroot->left) > gethight(newroot->right))
    {
        newroot->hight = 1 + gethight(newroot->left);
    }
    else if (gethight(newroot->left) < gethight(newroot->right))
    {
        newroot->hight = 1 + gethight(newroot->right);
    }
    else
    {
        newroot->hight = 1 + gethight(newroot->left);
    }
    return newroot;
}
Node *rightrotate(Node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return NULL;
    }
    Node *temp = root->left->right;     //1,当前节点的左子树作为新树的根节点
    Node *newroot = root->left;         //2, 当前节点作为新根节点的右子树
    newroot->right = root;
    root->left = temp;
    // 更新老树高
    if (gethight((root)->left) > gethight((root)->right))
    {
        (root)->hight = 1 + gethight((root)->left);
    }
    else if (gethight((root)->left) < gethight((root)->right))
    {
        (root)->hight = 1 + gethight((root)->right);
    }
    else
    {
        (root)->hight = 1 + gethight((root)->left);
    }
    // 更新新树高度
    if (gethight(newroot->left) > gethight(newroot->right))
    {
        newroot->hight = 1 + gethight(newroot->left);
    }
    else if (gethight(newroot->left) < gethight(newroot->right))
    {
        newroot->hight = 1 + gethight(newroot->right);
    }
    else
    {
        newroot->hight = 1 + gethight(newroot->left);
    }
    return newroot;
}

void insertNode(Node **root, int num)//插入节点
{

    Node *newNode = crearteNode(num);//初始化节点
    if (*root == NULL)//根为空 存放
    {
        *root = newNode;
        return;
    }

    Node *temp = *root;
    if (num > temp->data)//判断插入位置
    {

        insertNode(&(*root)->right, num);
    }
    else if (num < temp->data)
    {

        insertNode(&(*root)->left, num);
    }
    else
    {
        return;
    }
    // 更新高度
    if (gethight((*root)->left) > gethight((*root)->right))
    {
        (*root)->hight = 1 + gethight((*root)->left);
    }
    else if (gethight((*root)->left) < gethight((*root)->right))
    {
        (*root)->hight = 1 + gethight((*root)->right);
    }
    else
    {
        (*root)->hight = 1 + gethight((*root)->left);
    }

    int Balance = getBalance(*root);//获取当前节点的平衡因子
    // 判断平衡 有四种情况

    if (Balance < -1 && getBalance((*root)->right) <= 0) // RR型 根节点左旋一次
    {                                                   //平衡因子 为 根<-1 右子树 <=0  等于0说明右子树有两个节点
        printf("RR型:\n");  
        *root = leftrotate(*root);
    }
    else if (Balance < -1 && getBalance((*root)->right) > 0) // RL型 右子树右旋一次 转为 RR型 再 根节点左旋一次
    {                                                          //平衡因子 为 根<-1 右子树 > 0  说明右子树的右子树为空
        printf("RL型:\n");
        (*root)->right = rightrotate((*root)->right);
        *root = leftrotate(*root);
    }
    else if (Balance > 1 && getBalance((*root)->left) >= 0) // LL型 根节点右旋一次
    {                                                       //平衡因子 为 根>1 左子树 >=0  等于0说明左子树有两个节点
        printf("RR型:\n");  
        printf("LL型:\n");
        *root = rightrotate(*root);
    }
    else if (Balance > 1 && getBalance((*root)->left) < 0) // LR型 左子树左旋一次 转为 LL型 再 根节点右旋一次
    {                                                        //平衡因子 为 根>1 左子树 <0  等于0说明左子树的左子树为空
        printf("LR型:\n");
        (*root)->left = leftrotate((*root)->left);
        *root = rightrotate(*root);
    }
    else
    {
        return;
    }
}

void proshow(Node *node)//先序遍历
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->data);
    proshow(node->left);
    proshow(node->right);
}
void modshow(Node *node)//中序遍历
{
    if (node == NULL)
    {
        return;
    }
    modshow(node->left);
    printf("%d ", node->data);
    modshow(node->right);
}
void findNode(Node *root, int num)//查找节点
{
    if (root == NULL)
    {
        printf("为空!");
        return;
    }
    if (root->data == num)
    {
        printf("\n找到了,值为:%d", root->data);
        printf("\n差找了%d次", count);
    }
    else if (root->data > num)
    {
        count += 1;
        findNode(root->left, num);
    }
    else if (root->data < num)
    {
        count += 1;
        findNode(root->right, num);
    }
    else
    {
        printf("\n没有对应值", count);
        return;
    }
}
Node *findMin(Node *node)//查找最小节点
{
    if (node == NULL)
    {
        return NULL;
    }
    while (node->left)
    {
        node = node->left;
    }
    return node;
}
void delNode(Node **root, int del)//删除节点操作
{
    if (*root == NULL)
    {
        printf("\n没有对应值", count);
        return;
    }
    if ((*root)->data < del)//查找需要删除的节点
    {
        delNode(&(*root)->right, del);
    }
    else if ((*root)->data > del)
    {
        delNode(&(*root)->left, del);
    }
    else
    {
        if ((*root)->right == NULL && (*root)->left == NULL)//查找到 删除节点有四种情况
        {
            Node *temp = *root;//直接释放
            free(temp);
            *root = NULL; 
        }
        else if ((*root)->right == NULL && (*root)->left)//右为空
        {
            Node *temp = *root;
            *root = (*root)->left; // 获取子节点
            free(temp);            // 释放该节点
        }
        else if ((*root)->right && (*root)->left == NULL)//左为空
        {
            Node *temp = *root;
            *root = (*root)->right; // 获取子节点
            free(temp);             // 释放该节点
        }
        else                        //右两个子节点的情况
        {
            Node *minnide = findMin((*root)->right);//获取右节点的最小节点
            (*root)->data = minnide->data;          //将该节点的值替换为最小节点的值
            delNode(&(*root)->right, minnide->data);//递归右子树 释放最小节点 ! 一定要递归右子树 不能直接递归改最小节点
        }                                                                   //这样可以保证删除后的 AVL 树仍然保持平衡
    }                       
    if (*root == NULL) // 这段代码是在检查一个名为root的变量是否为空。因为在上面已经释放掉root了
    {                  // 这样做的目的是避免在处理空指针时出现错误或未定义的行为。
        return;         
    }
    // 更新高度
    (*root)->hight = gethight((*root)->left) > gethight((*root)->right) ? gethight((*root)->left) + 1 : gethight((*root)->right) + 1;
    // 判断平衡
    int Balance = getBalance(*root);
    if (Balance > 1 && getBalance((*root)->left) >= 0)
    {
        *root = rightrotate(*root);
    }
    else if (Balance > 1 && getBalance((*root)->left) < 0)
    {
        (*root)->left = leftrotate((*root)->left);
    }
    else if (Balance < -1 && getBalance((*root)->right) <= 0)
    {
        *root = leftrotate(*root);
    }
    else if (Balance < -1 && getBalance((*root)->right) > 0)
    {
        (*root)->right = rightrotate((*root)->right);
        *root = leftrotate(*root);
    }
    else
    {
        return;
    }
}

int main()
{
    Tree tree;
    tree.root = NULL;
    insertNode(&tree.root, 10);//存入
    insertNode(&tree.root, 8);
    insertNode(&tree.root, 9);
    insertNode(&tree.root, 6);
    printf("\n先序遍历:");
    proshow(tree.root);
    printf("\n中序遍历:");
    modshow(tree.root);
    printf("\n树高:%d", gethight(tree.root));//打印树高度
    printf("\n平衡因子:%d", getBalance(tree.root));//打印根的平衡因子
    findNode(tree.root, 10);//查找值
    delNode(&tree.root, 9);//删除节点
    printf("\n先序遍历:");
    proshow(tree.root);
    printf("\n中序遍历:");
    modshow(tree.root);
    return 0;
}