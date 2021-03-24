#include"head.h"

void menu_vip()
{
    int choice;
    head_info();
    printf("\t\t\t��ѡ��\n");
    printf("\t\t\t1.ע���Ա\n");
    printf("\t\t\t2.��ʾ���л�Ա��Ϣ\n");
    printf("\t\t\t3.�޸Ļ�Ա�Ǽ�\n");
    printf("\t\t\t4.���һ�Ա\n");
    printf("\t\t\t0.����\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:addv(); break;
    case 2:showv(); break;
    case 3:changev(); break;
    case 4:searchv(); break;
    case 0:gotoMainmenu(); break;
    }
}

void menu_managestatistics()
{
    head_info();
    printf("\t\t\t1.ע���µ�Ա���˺�\n");
    printf("\t\t\t2.ɾ��Ա����Ϣ\n");
    printf("\t\t\t3.չʾ����Ա����Ϣ\n");
    printf("\t\t\t4.����Ա������\n");
    printf("\t\t\t5.��ӹ���Ա\n");
    printf("\t\t\t0.������һ��\n");
    printf("\n\t\t\t��ѡ������Ҫ���еĲ�����");
    int choice;
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:registerUser(1); break;
    case 2:deleteStatistics_account(); break;
    case 3:showStatistics_account(); break;
    case 4:resetPassword_admin(); break;
    case 5:addAdmin(); break;
    case 0:mainmenu_admin(); break;
    }
}

//Ա��������
void mainmenu_employee()
{
    head_info();
    printf("\t\t\t1.�޸ĸ�����Ϣ\n");
    printf("\t\t\t2.����\n");
    printf("\t\t\t0.�˳�\n");
    printf("\n\t\t\t��ѡ������Ҫ���еĲ�����");
    int choice;
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:changeStatistics_user(); break;
    case 2:check_out(); break;
    case 0:login(); break;
    }
}

void head_info()
{
    char str[30];
    time_t t;
    struct tm* lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(str, 30, "%Y-%m-%d", lt);

    if (0 == strcmp(info_login->idtype, "����Ա"))
        printf("\t\t\t�𾴵�%s,���ǹ���Ա:-)\n", info_login->name);
    if (0 == strcmp(info_login->idtype, "Ա��"))
        printf("\t\t\t�𾴵�%s,����Ա��:-)\n", info_login->name);
    printf("\n\t\t\t\t\t\t\t��¼����:%s", str);
    printf("\n\t\t\t**************************************************\n\n");
}

//����Ա������
void mainmenu_admin()
{
    head_info();
    printf("\t\t\t1.�����˺�\n");
    printf("\t\t\t2.��Ŀ\n");
    printf("\t\t\t3.��Աϵͳ\n");
    printf("\t\t\t0.�˳�\n");
    printf("\n\t\t\t��ѡ������Ҫ���еĲ�����");
    int choice;
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:menu_managestatistics(); break;
    case 2: menu_record(); break;
    case 3:menu_vip(); break;
    case 0:login(); break;
    }
}

void menu_record()
{
    while (1)
    {
        printf("\t\t\t\t��������Ҫ���еĲ���\n\t\t\t\t1.�鿴�������ۼ�¼2.�����������ۼ�¼3.��ѯ���ۼ�¼ 0.���أ�");
        int choice;
        scanf("%d", &choice);
        system("cls");
        if (1 == choice || 2 == choice || 3 == choice || 0 == choice)
        {
            switch (choice)
            {
            case 1:showRecord(); break;
            case 2:createExcel(); break;
            case 3:searchRecord(); break;
            case 0:gotoMainmenu(); break;
            }
            break;
        }
        else printf("\n\t\t\t\t�������ʾѡ��");
        system("cls");
    }
}