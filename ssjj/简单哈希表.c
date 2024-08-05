#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 31
//使用链表来处理冲突是因为哈希函数可能会将不同的键映射到相同的桶（bucket）中。
//当两个或多个键具有相同的哈希值时，它们将被存储在同一个桶中。为了避免覆盖原有的键值对
//，我们可以使用链表来链接这些具有相同哈希值的键值对。
typedef struct list//构造哈希的链表存放 key 和 value
{
    const char * key;
    int value;
    struct list *next;
}list;

typedef struct Hashmap//构造哈希标 buckets 为桶 桶存放相同的键 , 为了不覆盖掉值 所以用链来存储,避免哈希冲突
{
    int count;
    list * buckets [HASH_SIZE];
}Hashmap;

int hash(const char * key)//计算哈希key 返回index 下标
{
    int index = 0;
    for (int i = 0; key[i]; i++)
    {
        index += key[i];
    }
    return index % HASH_SIZE;
} 

Hashmap * creatHashmap()//哈希初始化
{
    Hashmap * map = (Hashmap*)malloc(sizeof(Hashmap));//哈希指针内存分配
    memset(map,0,sizeof(Hashmap));//初始化内容全为零
    return map;
}

void inserthash(Hashmap *map,const char *key,int value)//插入 键 值
{
    int index = hash(key);//用键 计算下标
    printf("index:%d\n",index);
    list *newlist = (list*)malloc(sizeof(list));//新建链表节点存放 键和值
    newlist->key = strdup(key);
    newlist->value = value;

    newlist->next = map->buckets[index];//插入到桶的前一个节点 ,如果有相同的下标 ,一样会链接到前一个节点不会覆盖(头插入)
    map->buckets[index] = newlist;//移动桶下标到前节点
    map->count++;//数量++
}

int findhash(Hashmap *map,const char * key)//查找键值
{
    int index = hash(key);//获取下标
    printf("find index:%d\n",index);
    list * curront = map->buckets[index];//获取目标下标的桶
    printf("%s\n",curront->key);
    printf("%d\n",curront->value);
    while (curront != NULL)//循环 桶 的链表
    {
        
        if (strcmp(key,curront->key) == 0)//判断 正确的 链 返回value
        {
            return curront->value;
        }
        curront = curront->next;
    }
    return -1;
}
void freeHashmap(Hashmap **map)//释放哈希表
{
    if ((*map)->count == 0)
    {
        printf("表为空\n");
        return;
    }
    for (int i = 0; i < HASH_SIZE;  i++)//循环 哈希表桶容量
    {
        list * curront = (*map)->buckets[i];//获取桶
        while (curront != NULL)//循环释放该桶内的链节点
        {
            list * temp = curront->next;//存放下一个节点
            free((void*)curront->key);//释放节点的键
            free(curront);//释放节点
            curront = temp;
        }
        
    }
    free(*map);//释放哈希指针
    
}
int main()
{
    Hashmap * map = creatHashmap();
    inserthash(map,"acc",1);
    inserthash(map,"cac",2);
    inserthash(map,"bc",3);
    printf("value:%d\n",findhash(map,"cac"));
    freeHashmap(&map);

}