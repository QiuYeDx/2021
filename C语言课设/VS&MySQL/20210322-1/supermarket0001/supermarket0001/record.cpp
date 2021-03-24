#include"head.h"

LNode createList_record()
{
    LNode pHead = (LNode)malloc(LEN1);
    pHead->next = NULL;
    FILE* fp = fopen("record.bin", "ab+");
    fclose(fp);
    fp = fopen("record.bin", "rb");
    LNode cur = pHead;
    while (1)
    {
        LNode temp = (LNode)malloc(LEN1);
        if (!temp) exit(-1);
        if (!fread(temp, LEN1, 1, fp))
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

void addRecord(LNode Record)
{
    record rec = *Record;
    LNode pRec = &rec;
    strcpy(pRec->id, info_login->id);
    strcmp(pRec->id, info_login->id);
    FILE* fp = fopen("record.bin", "ab+");
    fwrite(pRec, LEN1, 1, fp);
    fclose(fp);
}

LNode searchRecord_vip(LNode head)
{
    char vip[15];
    while (1)
    {
        printf("��������Ҫ��ѯ��¼�Ļ�Ա�˺ţ�");
        scanf("%s", vip);
        LNode temp = head->next;
        int flag0 = 0;
        while (temp)
        {
            if (0 == strcmp(temp->vip, vip) )
            {
                flag0 = 1;
                printf("%s\t%s\t%s\t%.2f\t%.2f\n", temp->time,temp->vip,temp->id,temp->receive,temp->profit);
            }
            temp = temp->next;
        }
        if (0 == flag0)
        {
            printf("\n\t\t\t\t:-(  �������Ѽ�¼");
        }
        printf("\n\n\t\t\t\t�밴���������...");
        _getch();
        system("cls");
        menu_record();
    }
}

LNode searchRecord_date(LNode head)
{
    char date[15];
    while (1)
    {
        printf("��������Ҫ��ѯ��¼�����ڣ���ʽ����20200101����");
        scanf("%s", date);
        LNode temp = head->next;
        int flag0 = 0;
        while (temp)
        {
            char t_date[9];
            for (int i = 0; i < 4; i++)    t_date[i] = temp->time[i];
            for (int i = 5; i < 7; i++)    t_date[i-1] = temp->time[i];
            for (int i = 8; i < 10; i++)    t_date[i-2] = temp->time[i];
            if (0 == strcmp(t_date, date))
            {
                flag0 = 1;
                printf("%s\t%s\t%s\t%.2f\t%.2f\n", temp->time, temp->vip, temp->id, temp->receive, temp->profit);
            }
            temp = temp->next;
        }
        if (0 == flag0)
        {
            printf("\n\t\t\t\t:-(  �������Ѽ�¼");
        }
        printf("\n\n�밴���������...");
        _getch();
        system("cls");
        menu_record();
    }
}

void output(LNode head)
{
    LNode temp = head;
    printf("����ʱ��\t��Ա����\t�տ�Ա��\t�տ��\t����\t\n");
    while (temp)
    {
        printf("%s\t%s\t%s\t%.2f\t%.2f\n", temp->time, temp->vip, temp->id, temp->receive, temp->profit);
        temp = temp->next;
    }
    printf("\n\n�밴���������...");
    _getch();
    system("cls");
    menu_record();
}

void searchRecord()
{
    LNode head = createList_record();
    LNode temp = head->next;
    int choice;
    while (1)
    {
        printf("\t\t\t\t��ѡ����ҵķ�ʽ \n\t\t\t\t��1������\n\t\t\t\t��2����Ա�˺ţ�\n\t\t\t\t���������ѡ��");
        scanf("%d", &choice);
        system("cls");
        if (1 == choice || 2 == choice)
        {
            switch (choice)
            {
            case 1: searchRecord_date(head); break;
            case 2: searchRecord_vip(head); break;
            }
            output(head);
            break;
        }
        else printf("\t\t\t\t��ѡ�� 1 �� 2 ��");
    }
}

void showRecord()
{
    LNode head = createList_record();
    LNode temp = head->next;
    output(temp);
}

void createExcel()
{
    LNode head = createList_record();
    LNode temp = head->next;
    FILE*fp = fopen("record.xls", "w");
    fprintf(fp, "����ʱ��\t��Ա����\t�տ�Ա��\t�տ��\t��������\n");
    while (temp)
    {
        fprintf(fp,"%s\t%s\t%s\t%.02lf\t%.02lf\n", temp->time, temp->vip, temp->id, temp->receive, temp->profit);
        temp = temp->next;
    }
    fclose(fp);
    printf("�ѵ���Ϊ record.xls ����鿴��");
    Sleep(300);
    system("cls");
    menu_record();
}

void backup()
{
    system("copy record.bin e:\\backup");
}