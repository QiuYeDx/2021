#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "head.h"
#define LEN sizeof(vip)

/**********************************函数****************************************/

pv createv()     //用于将文件数据读入动态链表中
{
    pv pHead = (pv)malloc(LEN);
    pHead->next = NULL;
    FILE* fp = fopen("vip.bin", "a+");
    fclose(fp);
    fp = fopen("vip.bin", "rb");
    pv cur = pHead;
    while (1)
    {
        pv temp = (pv)malloc(LEN);
        if (!temp) exit(-1);
        if (!fread(temp, LEN, 1, fp))     //如果没读到
        {
            free(temp);
            break;
        }
        cur->next = temp;
        cur = temp;
        cur->next = NULL;
    }
    fclose(fp);
    return pHead;
}

int addv()        //用于添加vip
{
    system("cls");
    pv head = createv();
    pv temp = head->next;
    if (NULL == temp)
    {
        temp = (pv)malloc(LEN);
        head->next = temp;
    }
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        pv last = (pv)malloc(LEN);
        temp->next = last;
        temp = last;
    }
    temp->next = NULL;
    printf("\t\t***********您正在添加会员，添加过程中可随时按 # 键后回车以取消添加！*********\n");
    //姓名
    printf("\n\n\t\t\t请输入会员姓名:");
    scanf("%s", temp->name);
    cancelAction(temp->name);
    //性别
    while (1)
    {
        getchar();
        printf("\n\t\t\t请输入会员性别（男/女）:");
        scanf("%s", temp->sex);
        cancelAction(temp->sex);
        if (0==strcmp(temp->sex,"男") || 0 == strcmp(temp->sex, "女")) break;//判断数据是否合法
        else printf("\n\t\t\t请输入“男”或“女”！");
        clearLine(-3);
    }
    //电话号码
    while (1)
    {
        printf("\n");
        clearLine(0);
        printf("\t\t\t请输入会员的电话号码：");
        scanf("%s", temp->phone);
        cancelAction(temp->phone);
        if (11 == strlen(temp->phone)) break;
        else printf("\n\t\t\t请输入一个11位的手机号！");
        clearLine(-3);
    }
    //星级
    while (1)
    {
        getchar();
        printf("\n");
        clearLine(0);
        printf("\t\t\t请输入会员的星级：");
        scanf("%c", &temp->star);
        if (temp->star >= '1' && temp->star <= '3') break;
        else printf("\n\t\t\t请输入1-3之间的数字！");
        clearLine(-3);
    }
    temp->cost = 0;          //消费额，默认为0
    //将数据录入文件中
    FILE* fp = fopen("vip.bin", "ab+");
    fwrite(temp, LEN, 1, fp);
    fclose(fp);
    printf("\t\t\t信息录入成功！\n");
    Sleep(200);
    printf("\t\t\t您已成功添加！\n");
    Sleep(500);
    system("cls");
    menu_vip();
    return 1;
}

void showv()     //用于输出所有会员信息
{
    system("cls");
    printf("所有vip信息如下：\n");
    pv head = createv();
    pv temp = (pv)malloc(LEN);
    temp = head->next;
    printf("\t星级\t       姓名\t   \t 电话号码\t\t\t性别\t消费额\n");
    while (temp)
    {
        printf("%10c\t %10s\t\t%10s\t\t%10s", temp->star, temp->name, temp->phone,temp->sex);
        printf("\t   %d\n", temp->cost);
        temp = temp->next;
    }
    _getch();
    system("cls");
    menu_vip();
}

int changev()     //用于修改星级
{
    clearLine(0);
    int cost;    //跟修改消费额有关
    vip v;
    int i = 0, find = 0;    //用来标记是否找到
    char star, choose, yes;
    FILE* fp = fopen("vip.bin", "rb+");
    char phone[12];
    while (1)
    {
        printf("\n\t\t\t请输入需要修改的会员的电话号码：");
        scanf("%s", phone);
        cancelAction(phone);
        if (11 == strlen(phone)) break;
        else
        {
            printf("\n\t\t\t请输入一个正确的11位电话号码！");
            clearLine(-3);
        }
    }
    getchar();
    pv head = createv();
    pv temp = head->next;
    do
    {
        if (strcmp(temp->phone, phone) == 0)
        {
            find = 1;    //表示已找到。
            break;
        }
        i++;
    } while (temp = temp->next);
    if (find == 0)
    {
        printf("未找到此用户！\n");
        return 0;
    }
    while (1)
    {
        printf("请输入修改后的星级：");
        scanf("%c", &star);
        if (star >= '1' && star <= '3') break;
        else if (star == '#') return 0;
        else printf("请输入1-3之间的值！\n");
    }
    fseek(fp, i * LEN, 0);
    fwrite(&star, 1, 1, fp);
    printf("修改成功！\n");
    Sleep(100);
    fclose(fp);
    menu_vip();
    return 0;
}

int searchv()     //根据电话号码查找特定vip的信息。
{
    system("cls");
    int find = 0;    //用来标记是否找到
    char phone[12];
    while (1)
    {
        printf("请输入需要查找的会员的电话号码：");
        scanf("%s", phone);
        if (11 == strlen(phone)) break;
        else if (phone[0] == '#' && phone[1] == '\0')
        {
            printf("\t\t\t您已取消！\n");
            Sleep(1000);
            system("cls");
            return 0;
        }
        else printf("请输入一个正确的11位电话号码！\n");
    }
    getchar();
    pv head = createv();
    pv temp = head->next;
    do
    {
        if (strcmp(temp->phone, phone) == 0)
        {
            find = 1;    //表示已找到。
            break;
        }
    } while (temp = temp->next);
    if (find == 0)
    {
        printf("未找到此用户！\n");
        menu_vip();
        return 0;
    }
    printf("星级：%c\n姓名：%s\n", temp->star, temp->name);
    if (temp->sex == 0) printf("性别：女\n");
    else printf("性别：男\n");
    printf("消费额：%d\n", temp->cost);
    menu_vip();
}
    
sp createshop()      //用于将文件数据读入动态链表中
{
    sp pHead = (sp)malloc(L);
    pHead->next = NULL;
    FILE*fp = fopen("temp.bin", "r+");
    sp cur = pHead;
    while (1)
    {
        sp temp = (sp)malloc(L);
        if (!temp) exit(-1);
        if (5!=fscanf(fp, "%d%s%lf%lf%d", &temp->id, temp->name, &temp->cost, &temp->price, &temp->num))     //如果没读到
        {
            free(temp);
            break;
        }
        cur->next = temp;
        cur = temp;
        cur->next = NULL;
    }
    fclose(fp);
    return pHead;
}

LNode check_out()      //根据shopping结构体返回含利润应付款等的结构体
{
    getchar();
    char yes;                   //是否是vip
    double sumj = 0, sums = 0;       //进价和，售价和
    double money = 0, profit = 0;    //应付款，利润
    char phone[12];             //vip的电话
    while (1)
    {
        printf("输入1代表是vip，0代表不是vip:");
        scanf("%c", &yes);
        if (yes == '1' || yes == '0')
            break;
        else printf("请输入 0 或 1 ！\n");
    }
    sp head = createshop();
    sp temp = head->next;
    do
    {
        sumj += (temp->num) * (temp->cost);
        sums += (temp->num) * (temp->price);
        
    } while (temp = temp->next);
 
    if (yes == '1')              //如果是会员，接下来计算打折后的应付款
    {
        while (1)
        {
            printf("请输入会员的电话号码：");
            scanf("%s", phone);
            if (11 == strlen(phone)) break;
            else printf("请输入一个正确的11位电话号码！\n");
        }
        /**根据电话号找到对应VIP**/
        pv head = createv();
        pv temp = head->next;
        do
        {
            if (strcmp(temp->phone, phone) == 0)      //已找到
            {
                break;
            }
        } while (temp = temp->next);
        if (temp->star == '1') { money = 0.9 * sums; }
        else if (temp->star == '2') { money = 0.8 * sums; }
        else { money = 0.7 * sums; }
    }
    system("cls");
    profit = money - sumj;
    LNode r=(LNode)malloc(LEN1);                    //一会返回这个结构体指针
    time_t t;
    struct tm* lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(r->time, 25, "%Y-%m-%d %H:%M:%S", lt);
    
    if ('1' == yes)
    {
        r->profit = money - sumj;
        strcpy(r->vip, phone);
        r->receive = money;
        printf("\n\n\t\t\t  会员号:%s\n\n",r->vip);
    }
    else
    {
        r->profit = sums-sumj;
        r->receive = sums;
        strcpy(r->vip, "NULL");
    }
    r->next = NULL;
    showShop(sums, r->receive);
    addRecord(r);
    return r;
}

void showShop(double sum,double pay)
{
    sp head = createshop();
    sp temp = head->next;
    printf("\t\t\t+");
    for (int i = 0; i < 16; i++) printf("——");
    printf("+\n");
    printf("\t\t\t|     商品序号\t     商品名称\t      商品单价\t      数量\t |\n");
    
    printf("\t\t\t+");
    for (int i = 0; i < 16; i++) printf("——");
    printf("+\n");
    while (temp)
    {
        printf("\t\t\t|\t%d\t     %s\t\t%.2f\t\t%d\t |\n",temp->id,temp->name,temp->price,temp->num);
        temp = temp->next;
    }

    printf("\t\t\t+");
    for (int i = 0; i < 16; i++) printf("——");
    printf("+\n");

    printf("\t\t\t|\t\t\t\t\t 总价：%.2f\t\t |\n",sum);
    printf("\t\t\t|\t\t\t\t\t 折扣：%.2f\t\t |\n",sum-pay);
    printf("\t\t\t|\t\t\t\t\t 应付：%.2f\t\t |\n",pay);
    printf("\t\t\t+");
    for (int i = 0; i < 16; i++) printf("——");
    printf("+\n");
    _getch();
    system("cls");
}

