#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct book {
    int No;               //ͼ����
    char location[100];   //�����
    char name[100];       //����
    char author[100];     //����
    char company[100];    //������
    char range[100];      //רҵ����
    int storage;          //���
    float price;          //�۸�
    struct book *next;
} BOOK;

typedef struct INFORMATION {
    int No;               //�û����
    char name[100];       //����
    char gender[100];     //�Ա�
    int state;            //״̬
    int number;           //ѧ��
    int account;          //��������
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
            printf("��ӭ����ͼ�����ϵͳ��\n");
            printf("1.��½\n");
            printf("0.�˳�\n");
            scanf("%d",&z);
            if(z==1) {
                system("cls");
                printf("�����������û��������룺\n");
                printf("username��");
                scanf("%s",username);
                printf("password��");
                scanf("%s",password);
                break;
            }
            if(z==0) {
                return 0;
            }
            if(z!=1&&z!=0) {
                printf("�����������������룡");
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
            flag=2;                      //flag=2��ʾ�û���Ϣ������
        } else {
            while(1) {
                if(strcmp(manager,username)==0) {
                    if(strcmp(managerkey,password)==0) {
                        flag=4;               //flag=4��ʾ����Ա��½
                        break;
                    }
                }
                if(strcmp(username,p->name)==0) {
                    if(strcmp(password,p->password)==0) {
                        flag=3;
                        break;           //flag=3��ʾ������ȷ
                    } else {
                        flag=1;           //flag=1��ʾ�������
                        printf("\n�����������������룡\n");
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
            printf("�û���Ϣ�����ڣ�����ע�ᣡ\n");
            printf("������ת��ע����棡\n");
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
            printf("�����Թ���Ա��ݽ���\n");
            system("pause");
        }
        if(strcmp(manager,username)!=0) {
            a1=2;
            printf("�������û���ݽ���\n");
            system("pause");
        }
//        printf("��ѡ���½��ʽ:\n");
//        printf("1.����Ա��½\n");
//        printf("2.�����û���½\n");
//        printf("0.�˳�\n");
//        scanf("%d",&a1);
        if(a1!=1&&a1!=2&&a1!=0) {
            printf("�����������������룡");
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
        printf("��ѡ��Ҫʹ�õĹ��ܣ�\n");
        printf("1.ͼ����Ϣ¼��\n");
        printf("2.ͼ����Ϣ��ѯ\n");
        printf("3.ͼ����Ϣ�޸�\n");
        printf("4.ͼ����Ϣɾ��\n");
        printf("5.����ע��\n");
        printf("0.����\n");

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
    printf("��1��������0����");
    scanf("%d",&z);
    if(z==0) {
        return ;
    }
}

void menu2() {
    int z,a3;
    while(1) {
        system("cls");

        printf("��ѡ��Ҫʹ�õĹ��ܣ�\n");
        printf("1.ͼ��״̬��ѯ\n");
        printf("2.������Ϣ��ѯ\n");
        printf("3.�������\n");
        printf("4.������\n");
        printf("0.����\n");

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
    printf("��1��������0����");
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
        printf("���ļ�����\n");
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
        printf("���ļ�����\n");
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
    int N=1;//���
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
        printf("������ͼ����Ϣ��\n");
        printf("������������");
        scanf("%s",&cur->name);

        printf("����������ţ�");
        scanf("%s",&cur->location);

        printf("������רҵ����");
        scanf("%s",&cur->range);

        printf("���������ߣ�");
        scanf("%s",&cur->author);

        printf("����������磺");
        scanf("%s",&cur->company);

        printf("������������");
        scanf("%d",&cur->storage);

        printf("������۸�");
        scanf("%f",&cur->price);
        printf("\n");

        printf("��1����¼�룬��0���¼��");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("û�д˹��ܣ����������룺");
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
        printf("��������Ҫ���ҵ�������");
        scanf("%s",name);
        if(cur==NULL) {
            printf("Ŀǰ��ͼ����Ϣ������¼�룡\n");
            system("pause");
            break;
        }
        while(1) {
            if(strcmp(name,cur->name)==0) {
                printf("\n�����:%s\n������%s\nרҵ����%s\n���ߣ�%s\n������:%s\n������%d\n�۸�%.2f\n",cur->location,cur->name,cur->range,cur->author,cur->company,cur->storage,cur->price);
                break;
            } else {
                if(cur->next!=NULL) {
                    cur=cur->next;
                } else {
                    printf("û�д�����Ϣ��");
                    break;
                }
            }
        }
        printf("��1������ѯ����0����");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("û�д˹��ܣ����������룺");
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
        printf("��������Ҫ�޸ĵ�������");
        scanf("%s",name);
        if(cur==NULL) {
            printf("Ŀǰ��ͼ����Ϣ��\n");
        }
        if(strcmp(name,cur->name)==0) {
            while(1) {
                printf("1.�޸�����\n2.�޸�רҵ����\n3.�޸�����\n4.�޸ĳ�����\n5.�޸Ŀ��\n6.�޸ļ۸�\n");
                scanf("%d",&choice);
                system("cls");
                switch(choice) {
                case 1:
                    printf("ԭ������%s\n��������",cur->name);
                    scanf("%s",&cur->name);
                    printf("�޸ĳɹ���\n");
                    break;
                case 2:
                    printf("ԭרҵ����%s\n��רҵ����",cur->range);
                    scanf("%s",&cur->range);
                    printf("�޸ĳɹ���\n");
                    break;
                case 3:
                    printf("ԭ���ߣ�%s\n�����ߣ�",cur->author);
                    scanf("%s",&cur->author);
                    printf("�޸ĳɹ���\n");
                    break;
                case 4:
                    printf("ԭ�����磺%s\n�³����磺",cur->company);
                    scanf("%s",&cur->company);
                    printf("�޸ĳɹ���\n");
                    break;
                case 5:
                    printf("ԭ��棺%d\n�¿�棺",cur->storage);
                    scanf("%d",&cur->storage);
                    printf("�޸ĳɹ���\n");
                    break;
                case 6:
                    printf("ԭ�۸�%.2f\n�¼۸�",cur->price);
                    scanf("%f",&cur->price);
                    printf("�޸ĳɹ���\n");
                    break;
                }
                printf("��1�����޸ı���������Ϣ����0����");
                scanf("%d",&z);
                if(z==0) {
                    break;
                }
            }
        } else {
            if(cur->next!=NULL) {
                cur=cur->next;
            } else {
                printf("û�д�����Ϣ��\n");
            }
        }
        printf("��1�����޸������鼮��Ϣ����0����");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("û�д˹��ܣ����������룺");
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
        printf("������Ҫɾ��ͼ���������");
        scanf("%s",name);

        if(cur==NULL) {
            printf("Ŀǰ��ͼ����Ϣ��ɾ��ʧ�ܣ�\n");
        }
        if(cur==tail_book) {
            if(strcmp(cur->name,name)==0) {
                head_book=NULL;
                tail_book=NULL;
                printf("ɾ���ɹ���\n");
            } else {
                printf("�޴�ͼ����Ϣ,ɾ��ʧ�ܣ�\n");
            }
        }
        if(cur!=tail_book) {
            while(1) {
                if(strcmp(cur->name,name)==0) {
                    if(cur==head_book) {
                        head_book=head_book->next;
                        printf("ɾ���ɹ���\n");
                        break;
                    } else if(cur==tail_book) {
                        for(pre=head_book; pre; pre=pre->next) {
                            if(pre->next==cur) {
                                break;
                            }
                        }
                        tail_book=pre;
                        pre->next=NULL;
                        printf("ɾ���ɹ���\n");
                        break;
                    } else {
                        for(pre=head_book; pre; pre=pre->next) {
                            if(pre->next==cur) {
                                break;
                            }
                        }
                        pre->next=cur->next;
                        printf("ɾ���ɹ���\n");
                        break;
                    }
                } else {
                    if(cur==tail_book) {
                        printf("�޴�ͼ����Ϣ��ɾ��ʧ�ܣ�\n");
                        break;
                    } else {
                        cur=cur->next;
                    }
                }
            }
        }

        printf("��1����ɾ������0����");
        while(1) {
            scanf("%d",&z);
            if(z==0) {
                return ;
            }
            if(z==1) {
                break;
            }
            if(z!=0&&z!=1) {
                printf("û�д˹��ܣ����������룺");
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
        printf("��ע�������Ϣ��\n");

        printf("������");
        scanf("%s",&cur->name);

        printf("�Ա�");
        scanf("%s",&cur->gender);

        printf("���룺");
        scanf("%s",&cur->password);

        printf("ѧ�ţ�");
        scanf("%d",&cur->number);
        printf("\n");

        cur->state=0;
        cur->account=0;

        printf("��1��������0����");
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
    printf("��������Ҫ���ҵ�������");
    scanf("%s",name1);
    while(1) {
        if(strcmp(name1,cur->name)==0) {
            printf("\n������%s\n�Ա�%s\nѧ�ţ�%d\n",cur->name,cur->gender,cur->number);
            printf("��1��������0����");
            scanf("%d",&z);
            if(z==0) {
                break;
            } else {
                system("cls");
                printf("��������Ҫ���ҵ�������");
                scanf("%s",name1);
                cur=head_info->next;
            }
        } else {
            if(cur->next!=NULL) {
                cur=cur->next;
            } else {
                printf("û�д�����Ϣ��");
                printf("��1��������0����");
                scanf("%d",&z);
                if(z==0) {
                    break;
                } else {
                    system("cls");
                    printf("��������Ҫ���ҵ�������");
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
//    printf("��������Ҫ���ͼ������");
//    scanf("%s",name);
//
//}
