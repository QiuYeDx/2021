#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct book {
    int No;               //图书编号
    char location[100];   //索书号
    char name[100];       //书名
    char author[100];     //作者
    char company[100];    //出版社
    char range[100];      //专业领域
    int storage;          //库存
    float price;          //价格
    struct book *next;
} BOOK;

typedef struct INFORMATION {
    int No;               //用户编号
    char name[100];       //姓名
    char gender[100];     //性别
    int state;            //状态
    int number;           //学号
    int account;          //借书数量
    char password[15];
    struct INFORMATION *next;
} info;

BOOK *head_book=NULL;
info *head_info=NULL;
BOOK *tail_book=NULL;
info *tail_info=NULL;

void readinfo_file();
void readbook_file();
void writeinfo_file();
void writebook_file();

void create_book();
void search_book();
void change_book();
void delete_book();
void register_info();
void search_info();
void borrow_info();
void return_info();
void menu1();
void menu2();

int main() {
    int a1,i=0,flag=0,z;
    char ch;
    char username[15];
    char password[15];
    char manager[]="admin";
    char managerkey[]="admin";
    info *p;

    FILE *fp;
    fp=fopen("information.txt","rb");

    readinfo_file();
    readbook_file();

    system("color F0");
    while(1) {
        while(1) {
            printf("欢迎进入图书管理系统！\n");
            printf("1.登陆\n");
            printf("0.退出\n");
            scanf("%d",&z);
            if(z==1) {
                system("cls");
                printf("请输入您的用户名和密码：\n");
                printf("username：");
                scanf("%s",username);
                printf("password：");
                scanf("%s",password);
                break;
            }
            if(z==0) {
                return 0;
            }
            if(z!=1&&z!=0) {
                printf("输入有误，请重新输入！");
                system("pause");
                system("cls");
            }
        }
//        while((ch=getch())!='\r') {
//            if(ch!=8) {
//                password[i]=ch;
//                i++;
//                putchar('*');
//            } else {
//                printf("\b");
//                printf(" ");
//                printf("\b");
//            }
//        }

        p=head_info;
        if(p==NULL) {
            flag=2;                      //flag=2表示用户信息不存在
        } else {
            while(1) {
                if(strcmp(manager,username)==0) {
                    if(strcmp(managerkey,password)==0) {
                        flag=4;               //flag=4表示管理员登陆
                        break;
                    }
                }
                if(strcmp(username,p->name)==0) {
                    if(strcmp(password,p->password)==0) {
                        flag=3;
                        break;           //flag=3表示密码正确
                    } else {
                        flag=1;           //flag=1表示密码错误
                        printf("\n密码有误，请重新输入！\n");
                        system("pause");
                        break;
                    }
                } else {
                    p=p->next;
                    continue;
                }
            }
        }
        if(flag==1) {
            flag=0;
            system("cls");
            continue;
        }
        if(flag==2||flag==0) {
            printf("用户信息不存在，请先注册！\n");
            printf("即将跳转到注册界面！\n");
            system("pause");
            register_info();
            flag=0;
            writeinfo_file();
            system("cls");
            continue;
        }
        if(flag==3) {
            flag=0;
        }
        if(flag==4) {
            flag=0;
        }

        //system("cls");
        if(strcmp(manager,username)==0) {
            a1=1;
            printf("您在以管理员身份进入\n");
            system("pause");
        }
        if(strcmp(manager,username)!=0) {
            a1=2;
            printf("您在以用户身份进入\n");
            system("pause");
        }
//        printf("请选择登陆方式:\n");
//        printf("1.管理员登陆\n");
//        printf("2.个人用户登陆\n");
//        printf("0.退出\n");
//        scanf("%d",&a1);
        if(a1!=1&&a1!=2&&a1!=0) {
            printf("输入有误，请重新输入！");
            system("pause");
            system("cls");
            continue ;
        }
        if(a1==0) {
            break;
        }



        if(a1==1) {
            menu1();
        }
        if(a1==2) {
            menu2();
        }
    }
    return 0;
}

void menu1() {
    int z=1,a2;

    while(1) {
        system("cls");
        printf("请选择要使用的功能：\n");
        printf("1.图书信息录入\n");
        printf("2.图书信息查询\n");
        printf("3.图书信息修改\n");
        printf("4.图书信息删除\n");
        printf("5.办理注册\n");
        printf("0.返回\n");

        scanf("%d",&a2);
        system("cls");

        switch(a2) {
        case 1:
            create_book();
            break;
        case 2:
            search_book();
            break;
        case 3:
            change_book();
            break;
        case 4:
            delete_book();
            break;
        case 5:
            register_info();
            break;
        case 0:
            return ;
        }
        writeinfo_file();
        writebook_file();
    }
    printf("按1继续，按0返回");
    scanf("%d",&z);
    if(z==0) {
        return ;
    }
}

void menu2() {
    int z,a3;
    while(1) {
        system("cls");

        printf("请选择要使用的功能：\n");
        printf("1.图书状态查询\n");
        printf("2.个人信息查询\n");
        printf("3.办理借书\n");
        printf("4.办理还书\n");
        printf("0.返回\n");

        scanf("%d",&a3);
        system("cls");

        switch(a3) {
        case 1:
            search_book();
            break;
        case 2:
            search_info();
            break;
        case 0:
            return ;
        }

        writeinfo_file();
        writebook_file();
    }
    printf("按1继续，按0返回");
    scanf("%d",&z);
    if(z==0) {
        return ;
    }
}

void readbook_file() {
    FILE *fp;
    fp=fopen("book.txt","rb");
    BOOK *cur;
    cur=(BOOK*)malloc(sizeof(BOOK));
    while(fread(cur,sizeof(BOOK),1,fp)) {
        if(head_book==NULL) {
            head_book=cur;
            tail_book=cur;
        } else {
            tail_book->next=cur;
            tail_book=cur;
        }
        tail_book->next=NULL;
        cur=(BOOK*)malloc(sizeof(BOOK));
    }
    free(cur);

    fclose(fp);
}

void readinfo_file() {
    FILE *fp;
    fp=fopen("information.txt","rb");
    info *cur;
    cur=(info*)malloc(sizeof(info));
    while(fread(cur,sizeof(info),1,fp)) {
        if(head_info==NULL) {
            head_info=cur;
            tail_info=cur;
        } else {
            tail_info->next=cur;
            tail_info=cur;
        }
        tail_info->next=NULL;
        cur=(info*)malloc(sizeof(info));
    }
    free(cur);
    fclose(fp);
}

void writebook_file() {
    int i;
    FILE *fp;
    BOOK *p;
    p=head_book;
    fp=fopen("book.txt","wb");
    if(fp==NULL) {
        printf("打开文件错误\n");
    }
    while(1) {
        if(p==NULL)
            break;
        fwrite(p,sizeof(BOOK),1,fp);
        if(p->next==NULL) {
            break;
        } else {
            p=p->next;
        }
    }
    fclose(fp);

}

void writeinfo_file() {
    FILE *fp;
    info *p;
    p=head_info;
    fp=fopen("information.txt","wb");
    if(fp==NULL) {
        printf("打开文件错误\n");
    }
    while(1) {
        if(p==NULL)
            break;
        fwrite(p,sizeof(info),1,fp);
        if(p->next==NULL) {
            break;
        } else {
            p=p->next;
        }
    }
    fclose(fp);
}

void create_book() {
    int i=0,z;
    int N=1;//编号
    BOOK *cur,*p;

    while(1) {
        p=head_book;
        system("cls");
        cur=(BOOK*)malloc(sizeof(BOOK));
        if(head_book==NULL) {
            head_book=cur;
            tail_book=cur;
            cur->next=NULL;
        } else {
            tail_book->next=cur;
            tail_book=cur;
            cur->next=NULL;
        }
        cur->No=N;
        printf("请输入图书信息：\n");
        printf("请输入书名：");
        scanf("%s",&cur->name);

        printf("请输入索书号：");
        scanf("%s",&cur->location);

        printf("请输入专业领域：");
        scanf("%s",&cur->range);

        printf("请输入作者：");
        scanf("%s",&cur->author);

        printf("请输入出版社：");
        scanf("%s",&cur->company);

        printf("请输入数量：");
        scanf("%d",&cur->storage);

        printf("请输入价格：");
        scanf("%f",&cur->price);
        printf("\n");

        printf("按1继续录入，按0完成录入");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("没有此功能，请重新输入：");
            }
        }
    }
}

void search_book() {
    char name[100];
    int z;
    BOOK *cur;

    while(1) {
        cur=head_book;
        system("cls");
        printf("请输入您要查找的书名：");
        scanf("%s",name);
        if(cur==NULL) {
            printf("目前无图书信息，请先录入！\n");
            system("pause");
            break;
        }
        while(1) {
            if(strcmp(name,cur->name)==0) {
                printf("\n索书号:%s\n书名：%s\n专业领域：%s\n作者：%s\n出版社:%s\n数量：%d\n价格：%.2f\n",cur->location,cur->name,cur->range,cur->author,cur->company,cur->storage,cur->price);
                break;
            } else {
                if(cur->next!=NULL) {
                    cur=cur->next;
                } else {
                    printf("没有此书信息！");
                    break;
                }
            }
        }
        printf("按1继续查询，按0返回");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("没有此功能，请重新输入：");
            }
        }

    }
}

void change_book() {
    int choice,z;
    char name[100];
    BOOK *cur;

    while(1) {
        cur=head_book;
        system("cls");
        printf("请输入您要修改的书名：");
        scanf("%s",name);
        if(cur==NULL) {
            printf("目前无图书信息！\n");
        }
        if(strcmp(name,cur->name)==0) {
            while(1) {
                printf("1.修改书名\n2.修改专业领域\n3.修改作者\n4.修改出版社\n5.修改库存\n6.修改价格\n");
                scanf("%d",&choice);
                system("cls");
                switch(choice) {
                case 1:
                    printf("原书名：%s\n新书名：",cur->name);
                    scanf("%s",&cur->name);
                    printf("修改成功！\n");
                    break;
                case 2:
                    printf("原专业领域：%s\n新专业领域：",cur->range);
                    scanf("%s",&cur->range);
                    printf("修改成功！\n");
                    break;
                case 3:
                    printf("原作者：%s\n新作者：",cur->author);
                    scanf("%s",&cur->author);
                    printf("修改成功！\n");
                    break;
                case 4:
                    printf("原出版社：%s\n新出版社：",cur->company);
                    scanf("%s",&cur->company);
                    printf("修改成功！\n");
                    break;
                case 5:
                    printf("原库存：%d\n新库存：",cur->storage);
                    scanf("%d",&cur->storage);
                    printf("修改成功！\n");
                    break;
                case 6:
                    printf("原价格：%.2f\n新价格：",cur->price);
                    scanf("%f",&cur->price);
                    printf("修改成功！\n");
                    break;
                }
                printf("按1继续修改本书其他信息，按0返回");
                scanf("%d",&z);
                if(z==0) {
                    break;
                }
            }
        } else {
            if(cur->next!=NULL) {
                cur=cur->next;
            } else {
                printf("没有此书信息！\n");
            }
        }
        printf("按1继续修改其他书籍信息，按0返回");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("没有此功能，请重新输入：");
            }
        }
    }
}

void delete_book() {
    int z;
    BOOK *cur,*pre;
    char name[100];

    while(1) {
        cur=head_book;
        system("cls");
        printf("请输入要删除图书的书名：");
        scanf("%s",name);

        if(cur==NULL) {
            printf("目前无图书信息，删除失败！\n");
        }
        if(cur==tail_book) {
            if(strcmp(cur->name,name)==0) {
                head_book=NULL;
                tail_book=NULL;
                printf("删除成功！\n");
            } else {
                printf("无此图书信息,删除失败！\n");
            }
        }
        if(cur!=tail_book) {
            while(1) {
                if(strcmp(cur->name,name)==0) {
                    if(cur==head_book) {
                        head_book=head_book->next;
                        printf("删除成功！\n");
                        break;
                    } else if(cur==tail_book) {
                        for(pre=head_book; pre; pre=pre->next) {
                            if(pre->next==cur) {
                                break;
                            }
                        }
                        tail_book=pre;
                        pre->next=NULL;
                        printf("删除成功！\n");
                        break;
                    } else {
                        for(pre=head_book; pre; pre=pre->next) {
                            if(pre->next==cur) {
                                break;
                            }
                        }
                        pre->next=cur->next;
                        printf("删除成功！\n");
                        break;
                    }
                } else {
                    if(cur==tail_book) {
                        printf("无此图书信息，删除失败！\n");
                        break;
                    } else {
                        cur=cur->next;
                    }
                }
            }
        }

        printf("按1继续删除，按0返回");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("没有此功能，请重新输入：");
            }
        }

    }
}

void register_info() {
    int z=1;
    info *cur;

    while(1) {
        system("cls");
        cur=(info *)malloc(sizeof(info));
        if(head_info==NULL) {
            head_info=cur;
            tail_info=cur;
            cur->next=NULL;
        } else {
            tail_info->next=cur;
            tail_info=cur;
            cur->next=NULL;
        }
        printf("请注册身份信息：\n");

        printf("姓名：");
        scanf("%s",&cur->name);

        printf("性别：");
        scanf("%s",&cur->gender);

        printf("密码：");
        scanf("%s",&cur->password);

        printf("学号：");
        scanf("%d",&cur->number);
        printf("\n");

        cur->state=0;
        cur->account=0;

        printf("按1继续，按0返回");
        scanf("%d",&z);

        if(z==0) {
            break;
        }
    }
}

void search_info() {
    char name1[15];
    int z;
    info *cur;
    cur=head_info;
    system("cls");
    printf("请输入您要查找的姓名：");
    scanf("%s",name1);
    while(1) {
        if(strcmp(name1,cur->name)==0) {
            printf("\n姓名：%s\n性别：%s\n学号：%d\n",cur->name,cur->gender,cur->number);
            printf("按1继续，按0返回");
            scanf("%d",&z);
            if(z==0) {
                break;
            } else {
                system("cls");
                printf("请输入您要查找的姓名：");
                scanf("%s",name1);
                cur=head_info->next;
            }
        } else {
            if(cur->next!=NULL) {
                cur=cur->next;
            } else {
                printf("没有此人信息！");
                printf("按1继续，按0返回");
                scanf("%d",&z);
                if(z==0) {
                    break;
                } else {
                    system("cls");
                    printf("请输入您要查找的书名：");
                    scanf("%s",name1);
                    cur=head_info;
                }
            }
        }
    }
}

//void borrow_info()
//{
//    char name[15];
//    BOOK *cur;
//    printf("请输入您要借的图书名：");
//    scanf("%s",name);
//
//}
