#include"head.h"

void menu_vip()
{
    int choice;
    head_info();
    printf("\t\t\t请选择：\n");
    printf("\t\t\t1.注册会员\n");
    printf("\t\t\t2.显示所有会员信息\n");
    printf("\t\t\t3.修改会员星级\n");
    printf("\t\t\t4.查找会员\n");
    printf("\t\t\t0.返回\n");
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
    printf("\t\t\t1.注册新的员工账号\n");
    printf("\t\t\t2.删除员工信息\n");
    printf("\t\t\t3.展示所有员工信息\n");
    printf("\t\t\t4.重置员工密码\n");
    printf("\t\t\t5.添加管理员\n");
    printf("\t\t\t0.返回上一级\n");
    printf("\n\t\t\t请选择你需要进行的操作：");
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

//员工主界面
void mainmenu_employee()
{
    head_info();
    printf("\t\t\t1.修改个人信息\n");
    printf("\t\t\t2.结账\n");
    printf("\t\t\t0.退出\n");
    printf("\n\t\t\t请选择你需要进行的操作：");
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

    if (0 == strcmp(info_login->idtype, "管理员"))
        printf("\t\t\t尊敬的%s,你是管理员:-)\n", info_login->name);
    if (0 == strcmp(info_login->idtype, "员工"))
        printf("\t\t\t尊敬的%s,你是员工:-)\n", info_login->name);
    printf("\n\t\t\t\t\t\t\t登录日期:%s", str);
    printf("\n\t\t\t**************************************************\n\n");
}

//管理员主界面
void mainmenu_admin()
{
    head_info();
    printf("\t\t\t1.管理账号\n");
    printf("\t\t\t2.账目\n");
    printf("\t\t\t3.会员系统\n");
    printf("\t\t\t0.退出\n");
    printf("\n\t\t\t请选择你需要进行的操作：");
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
        printf("\t\t\t\t请输入需要进行的操作\n\t\t\t\t1.查看所有销售记录2.导出所有销售记录3.查询销售记录 0.返回：");
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
        else printf("\n\t\t\t\t请根据提示选择！");
        system("cls");
    }
}