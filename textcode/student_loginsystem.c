#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_info
{
    char name[10];
    int age;
    int point;
}student_info;
struct student_info *n;
void input_student_info(student_info *n)
{
    
    printf("请输入姓名:\n");
    scanf("%s", n->name);
    printf("请输入年龄:\n");
    scanf("%d", &n->age);
    printf("请输入分数:\n");
    scanf("%d", &n->point);
}
void show_student_info(student_info *n)
{

    printf("姓名:%s\n", n->name);
    printf("年龄:%d\n", n->age);
    printf("分数:%d\n", n->point);
}
void login_read()
{

    char str_Person[15] = "123456";
    char str_Passwd[15] = "123456";
    char Person[15];
    char Passwd[15];

    printf("请输入账号：");
    scanf("%s", Person);
    printf("请输入密码：");
    scanf("%s", Passwd);
    if (strcmp(str_Person, Person) == 0 && strcmp(str_Passwd, Passwd) == 0)
    {
        printf("登录成功！!!");
        return;  
    }
    else
    {
        printf("%s", Person);
        printf("%s", Passwd);
        printf("账号或密码错误！");
        login_read();
    }
} 
void select_student_system(struct student_info *n)
{
    int i= 0;
    while(i<50)
    {
        int N = 0 ;
        system("clear");
        printf("---------选择需要的功能--------\n");
        printf("---------录入学生信息 .1.--------\n");
        printf("---------查看学生信息 .2.--------\n");
        printf("---------退出系统 .3.--------\n");
        scanf("%d",&N);
        switch (N)
        {
        case 1:input_student_info(n);
            break;
        case 2: show_student_info(n);
            printf("输入任意键继续用...");
            getchar();
            getchar();
            break;
         case 3: 
            return;
        }

        i++;
    }
}
int main()
{
    n = (struct student_info *)malloc(sizeof(struct student_info));
    login_read();
    select_student_system(n);
   
    free(n);
    n = NULL;
    return 0;
}