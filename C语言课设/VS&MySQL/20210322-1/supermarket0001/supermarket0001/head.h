#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#define LEN sizeof(account)
#define LEN1 sizeof(record)
#define L sizeof(struct Shopping)

typedef struct Account  //Ա���˺���Ϣ
{
    char idtype[10];//0Ϊ����Ա�˺ţ�1ΪԱ���˺�
    char id[9];//����(8λ����)
    char password[25];//����
    char name[15];
    char sex[4];//0ΪŮ��1Ϊ��
    char phone[12];
    float achievement;
    int status;//0��ʾ�˺�ͣ�ã�1��ʾ�˺�����
    struct Account* next;
}account, * pNode;

typedef struct Record
{
    char time[25];//��¼����ʱ��(��λ��)
    char id[10];//��¼Ա��
    char vip[12];//��¼���ѵĻ�Ա
    double receive;//��¼�տ��
    double profit;//��¼����
    struct Record* next;
}record, * LNode;

//vip
typedef struct VIP  //vip��Ϣ
{
    char star;                     //�Ǽ���1-3��9,8,7�ۣ�
    char name[15];
    char sex[4];                      //0ΪŮ��1Ϊ��
    char phone[12];
    int cost;                       //���Ѷ� 
    struct VIP* next;
}vip, * pv;

typedef struct Shopping
{
    int id;
    char name[30];
    double cost;//Jinjia
    double price;
    int num;
    struct Shopping* next;
}*sp;



extern pNode info_login;

pNode createList();
int registerUser(int);
int login();
void changeStatistics_user();
void deleteStatistics_account();
void showStatistics_account();
void mainmenu_admin();
void mainmenu_employee();
int vertify_password();
int resetPassword_admin();
int addAdmin();
void menu_managestatistics();
void Gotoxy(int x, int y);
void CursorUpOneLine();
void clearLine(int num);
void head_info();
void cancelAction(char in[]);
void gotoMainmenu();
pNode rankAccount_id(pNode head, int n);

void addRecord(LNode record);
void showRecord();
LNode createList_record();
void  output(LNode head);
void searchRecord();
LNode searchRecord_vip(LNode head);
LNode searchRecord_date(LNode head);
void createExcel();
void showRecord();
void menu_record();
void backup();



/**********************************��������**************************************/
pv createv();
int addv();
void showv();
int changev();
int searchv();
LNode check_out();

void menu_vip();
void showShop(double sum, double pay);
sp createshop();