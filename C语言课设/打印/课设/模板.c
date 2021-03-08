#pragma
//#define _CRT_SECURE_NO_WARNINGS
#define GAMETYPE_NUMBER 20
#define SCHOOL_NUMBER 20
#define EACH_NUMBER 10

extern char gametype[GAMETYPE_NUMBER][20];
extern char schooltype[SCHOOL_NUMBER][20];
typedef struct node {
	int num;
	double grade;
	char name[20], sex[10], school[20], type[20];
	struct node * next;
} Node, *student;
student Nodecreate();
student Lcreate();
student LfindTail(student head);
void Ldisplay(student head, int n);
void Lconnect(student head, student newhead);
student InsertSort(student head);
void Distinct_stu(student head, student subhead, int num);
int Lproject_num(student head);
void ShowTime();
void Delay(int ms);
void Animation();
void Login();
void ArrayLdestroy(student subhead, int n);
void eq();
void display(student subhead);
student load();
void Distinct_stu2(student head, student subhead2, int num);
void Search(student head);
#include "student.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <direct.h>
char gametype[GAMETYPE_NUMBER][20] = {};
char schooltype[SCHOOL_NUMBER][20] = {};
/*�������˶���Ŀ��ͬ���ַ����飬����������Ŀ�����󣬽����������������Ҫ���������н������������治ͬ����Ŀ��ͷ�ڵ㱣����Ŀ��Ϣ*/
int main()
{
	system("color B9");
	Animation();
	ShowTime();
	Login();
	Node *head = NULL;
	head = load();
	if (head == NULL) {
		printf("û�б������ݣ�������������\n");
		head = Lcreate();
	}
	system("cls");
	system("color f0");
	while (1) {
		system("cls");
		ShowTime();
		printf("\t\t\t\t\t\t  ������ѡ��\n\n\n\n");
		printf("\t*\t1 : ���ѧ���ɼ�\n\n");
		printf("\t*\t2 : ��ʾ������\n\n");
		printf("\t*\t3 : ��ʾ��������\n\n");
		printf("\t*\t4 : ����\n\n");
		printf("\t*\t5 : ��ձ�����Ϣ\n\n");
		printf("\t*\t6 : �˳�\n\n");

		int a = 0;
		scanf("%d", &a);
		switch (a) {
		case 1:
			system("cls");
			head = Lcreate();
			break;
		case 2:
			system("cls");
			head = load();
			Ldisplay(head, head->num);
			system("pause");
			break;
		case 3:
			system("cls");
			display(head);
			system("pause");
			break;
		case 4:
			system("cls");
			Search(head);
			break;
		case 5:
			system("cls");
			FILE *a;
			if ((a = fopen("D:\\ACYTXX\\result.txt", "w")) == NULL) {
				printf("�޷�������ݣ���ʼ��ʧ�ܣ�\n");
				system("pause");
			}
			break;
		case 6:
			eq();
			break;
		default:
			printf("��������ȷ��ѡ��\n");
			system("pause");
		}
	}
	system("cls");
	ArrayLdestroy(head, 1);
	system("pause");
	return 0;
}
#include "student.h"//������λ
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <direct.h>
#include <conio.h>

student Nodecreate() {
	Node *head;
	if ((head = (Node*)malloc(sizeof(Node*))) == NULL) {
		printf("�޷������ڵ㣡\n");
		system("pause");
		return 0;
	}
	head->next = NULL;
	return head;
}
student Lcreate()
{
	Node *head, *tail, *nnode;//headΪ����ͷָ�룬tailΪβָ�룬nnodeΪ�м䴦���ָ��
	FILE *result;
	if ((result = fopen("D:\\ACYTXX\\result.txt", "a")) == NULL) { //�ж��Ƿ����ҵ�resul.txt
		printf("�޷����棡\n");
		system("pause");
		fclose(result);
		return NULL;
	}
	char name_[20], sex_[10], school_[20], type_[20];
	int n = 0;
	double grade_;
	if ((head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("�޷��������������˳�\n");
		system("pause");
		exit(-1);
	}
	head->next = NULL;
	tail = head;
	printf("�����������������Ա�ѧԺ��������Ŀ���ɼ���EOF��������\n");//���������Ŀ������Ϣ����䵽result.txt�ļ���
	while (scanf("%s%s%s%s%lf", name_, sex_, school_, type_, &grade_) != EOF)
	{
		++n;
		if ((nnode = (Node *)malloc(sizeof(Node))) == NULL)
		{
			printf("�޷��������������˳�\n");
			system("pause");
			exit(-1);
		}
		nnode->next = NULL;
		strcpy(nnode->name, name_);
		strcpy(nnode->sex, sex_);
		strcpy(nnode->school, school_);
		strcpy(nnode->type, type_);
		nnode->grade = grade_;
		nnode->num = n;
		fprintf(result, "%-10s%-7s%-15s%-15s%-7g\n", nnode->name, nnode->sex, nnode->school, nnode->type, nnode->grade);//���ļ��м�¼
		tail->next = nnode;
		tail = nnode;
	}
	head->num = n;
	fclose(result);
	return head;
}
student LfindTail(student head) {		//�ҵ�βָ��
	Node *p;
	for (p = head; p->next != NULL; p = p->next);
	return p;
}
void Ldisplay(student head, int n)
{
	student p;
	int i = 0;
	for (p = head->next; p != NULL && i < n; p = p->next, ++i)
		printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);
}
void Lconnect(student head, student newhead) {		//�����������ڵ���������
	student rear;
	rear = LfindTail(head);
	rear->next = newhead;
	newhead->next = NULL;
}
student InsertSort(student head)
{
	Node *FakeNode = head->next;
	Node *first = NULL;
	Node *t = NULL;
	Node *p = NULL;
	Node *q = NULL;
	first = FakeNode->next;
	FakeNode->next = NULL;
	while (first != NULL) {
		for (t = first, q = FakeNode; ((q != NULL) && (q->grade > t->grade)); p = q, q = q->next);
		first = first->next;
		if (q == FakeNode) {
			FakeNode = t;
		}
		else {
			p->next = t;
		}
		t->next = q;
	}
	head->next = FakeNode;
	return head;
}
student load() {
	student head, tail, nnode;
	FILE *result;
	if ((result = fopen("D:\\ACYTXX\\result.txt", "r")) == NULL) {
		printf("�޷��������ļ���û�б������ݣ�\n");
		system("pause");
		return NULL;
	}
	if ((head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("�޷��������������˳�\n");
		system("pause");
		exit(-1);
	}
	head->next = NULL;
	tail = head;
	char name_[20], sex_[10], school_[20], type_[20];
	int n = 0;
	double grade_;
	while ((fscanf(result, "%s %s %s %s %lf", name_, sex_, school_, type_, &grade_) != EOF)) {
		++n;
		if ((nnode = (Node *)malloc(sizeof(Node))) == NULL)
		{
			printf("�޷��������������˳�\n");
			system("pause");
			exit(-1);
		}
		nnode->next = NULL;
		strcpy(nnode->name, name_); strcpy(nnode->sex, sex_); strcpy(nnode->school, school_); strcpy(nnode->type, type_); nnode->grade = grade_; nnode->num = n;
		tail->next = nnode;
		tail = nnode;
	}
	head->num = n;
	fclose(result);
	return head;
}
void Distinct_stu(student head, student subhead, int num) {
	head = load();
	Node *p, *temp;
	double sum = 0;
	for (p = head->next, temp = p->next; temp != NULL; p = temp, temp = temp->next) {
		for (int i = 0; i < num; i++)
			if (!strcmp(p->type, gametype[i]))
				Lconnect((subhead + i), p), sum += p->grade;
	}
	for (int i = 0; i < num; i++)
		if (!strcmp(p->type, gametype[i])) {
			Lconnect((subhead + i), p), sum += p->grade;
		}
	head->grade = sum;		//ͳ���ܷ�
	head->next = NULL;		//������ֻʣ��ͷ�ڵ�
}
int Lproject_num(student head) {		//������Ŀ��������
	student p;
	int j = 0, n = 0;
	for (p = head->next; p != NULL; p = p->next) {
		for (j = 0; j <= n; ++j) {
			if (!strcmp(p->type, gametype[j]))
				break;
		}			//�Ļ��ַ����飬���棬������Ĵ�С��¼.
		if (j > n)
			strcpy(gametype[--j], p->type), ++n;
	}
	return n;		//������Ŀ��������
}
int Lschool_num(student head) {		//����ѧԺ����
	student p;
	int j = 0, n = 0;
	for (p = head->next; p != NULL; p = p->next) {
		for (j = 0; j <= n; ++j) {
			if (!strcmp(p->school, schooltype[j]))
				break;
		}			//�Ļ��ַ����飬���棬������Ĵ�С��¼.
		if (j > n)
			strcpy(schooltype[--j], p->school), ++n;
	}
	return n;		//������Ŀ��������
}
void ShowTime() {
	char *wday[] = { "������","����һ","���ڶ�","������","������","������","������" };
	time_t t;
	struct tm *p;
	t = time(NULL);
	p = gmtime(&t);
	printf("\n%d��%2d��%2d��", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %s ", wday[p->tm_wday]);
	printf("%02d:%02d:%02d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);
}
void Delay(int ms)
{
	int i, j;
	for (i = ms; i>0; i--)
		for (j = 100000; j>0; --j);//�Զ���delay�������ӳ�ʱ�䣬��ʾ����

}
void Animation()
{
	system("cls");
	system("color Bc");
	printf("\n\n\t\t\t��");
	Delay(5000);
	system("cls");
	system("color Ba");
	printf("\n\n\t\t\t\tӭ\t");
	Delay(5000);
	system("cls");
	system("color Bd");
	printf("\n\n\t\t\t\t\tʹ\t");
	Delay(5000);
	system("cls");
	system("color B9");
	printf("\n\n\t\t\t\t\t\t��\t");
	system("cls");
	printf("\n\n\t\t\t��\tӭ\tʹ\t��");
	printf("\n\n\t\t\t������ѧ�˶���ɼ���¼ϵͳ\n");
	Delay(3000);
}
void Login()
{
	system("cls");
	char c_password[27], c_ori_code[27];
	FILE *fp, *ac;
	int i, x;
	if ((fp = fopen("D:\\ACYTXX\\p", "rb")) == NULL) {		//����Ƿ���ε�½
		if (_mkdir("D:\\ACYTXX") == -1) {
			printf("��ʼ��ʧ�ܣ�\n\n");
			system("pause");
			exit(1);
		}
		printf("\n\t\t\t\t  ���ε�½�������ó�ʼ����\n\n");
		char pa[20];
		for (i = 0; i<28; i++) {
			pa[i] = _getch();
			if (pa[i] == '\r')
				break;
			printf("*");
		}
		pa[i] = '\0';
		fp = fopen("D:\\ACYTXX\\p", "wb");
		fputs(pa, fp);
		fclose(fp);
		return;
	}
	printf("\n\t\t\t\t\t\t  ����������\n");

	for (x = 5; x>0; x--) {
		printf("\n\t�㻹��%d�λ���\n", x);
		fp = fopen("D:\\ACYTXX\\p", "rb");
		fscanf(fp, "%s", c_ori_code);
		for (i = 0; i<28; i++) {
			c_password[i] = _getch();
			if (c_password[i] == '\r')
				break;
			printf("*");
		}
		c_password[i] = '\0';
		if (strcmp(c_password, c_ori_code) != 0) {
			system("cls");
			ShowTime();
			system("color 0c");
			printf("\n\t\t\t\t\t\t �����������������:\n");
		}
		else
			return;
	}
	exit(1);
	return;
}
void ArrayLdestroy(student head, int n) {		//�������û�����⣬������ڷ���ʱ�����һ���ڵ�û��ָ��NULL
	Node *p, *q;
	for (int i = 0; i < n; ++i) {
		p = (head + i);
		while (p->next != NULL) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	free(head);
}
void eq()
{
	void ShowTime();
	system("cls");
	ShowTime();
	printf("\n\n\n\n\n\t\t\t\t\t\t    �˳���\n\n\t\t\t\t\t\t  'y' or 'n'\n\n\n");
	char m;
	getchar();
	scanf("%c", &m);
	if (m == 'y')
		exit(0);
}
void display(student head) {
	system("cls");
	int num = 0;
	num = Lproject_num(head);
	Node *subhead = (Node*)malloc(num * sizeof(Node));
	for (int i = 0; i < num; ++i)
		(subhead + i)->next = NULL;
	Distinct_stu(head, subhead, num);
	for (int i = 0; i < num; ++i)
		InsertSort(subhead + i);
	for (int i = 0; i < num; ++i) {
		printf("%s��ǰ����Ϊ\n\n", (subhead + i)->next->type);
		Ldisplay(subhead + i, 6), printf("\n\n");
	}
	ArrayLdestroy(subhead, num);
	//ͳ��ÿ��ѧԺ�ĳɼ����Ƚ�ѧ������ѧԺ���֣���ͳ�ƣ����������ÿ��ѧԺͷ�ڵ��double��
	head = load();
	int num2 = 0;
	num2 = Lschool_num(head);
	Node *subhead2 = (Node*)malloc(num2 * sizeof(Node));
	for (int i = 0; i < num2; ++i) {
		(subhead2 + i)->next = NULL;
		(subhead2 + i)->grade = 0;
	}
	Distinct_stu2(head, subhead2, num2);
	for (int i = 0; i < num2; ++i)		//�����ð������
		for (int j = num2 - 1; j > i; --j) {
			if ((subhead2 + j)->grade >(subhead2 + j - 1)->grade) {
				Node *temp;
				temp = (Node *)malloc(sizeof(Node));
				*temp = *(subhead2 + j);
				*(subhead2 + j) = *(subhead2 + j - 1);
				*(subhead2 + j - 1) = *temp;
			}
		}
	printf("������ӵ��ܷ�ǰ����Ϊ��\n\n");
	for (int i = 0; i < 3; ++i)
		printf("\t%s����ӵ��ܷ�Ϊ%g\n\n", (subhead2 + i)->next->school, (subhead2 + i)->grade);
	ArrayLdestroy(subhead2, num2);
}
void Distinct_stu2(student head, student subhead2, int num) {
	Node *p, *temp;

	for (p = head->next, temp = p->next; temp != NULL; p = temp, temp = temp->next) {
		for (int i = 0; i < num; i++)
			if (!strcmp(p->school, schooltype[i])) {
				Lconnect((subhead2 + i), p);
				((subhead2 + i)->grade) += p->grade;
			}
	}
	for (int i = 0; i < num; i++)
		if (!strcmp(p->school, schooltype[i])) {
			Lconnect((subhead2 + i), p);
			((subhead2 + i)->grade) += p->grade;
		}

	head->next = NULL;		//������ֻʣ��ͷ�ڵ�
}
void Search(student head) {
	head = load();
	int x = 1;
	while (x) {
		system("cls");
		ShowTime();
		printf("\t\t\t\t\t\t  ������ѡ��\n\n\n\n");
		printf("\t*\t1 : ����������\n\n");
		printf("\t*\t2 : ��������Ŀ����\n\n");
		printf("\t*\t3 : ��ѧԺ����\n\n");
		printf("\t*\t4 : �����ϲ�˵�\n\n");
		int n = 0;
		scanf("%d", &n);
		student p;
		switch (n) {
		case 1:
			printf("����������\n");
			char name[20];
			scanf("%s", name);
			for (p = head->next; p->next != NULL; p = p->next) {
				if (strstr(p->name, name))
					printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);
			}
			break;
		case 2:
			printf("�����������Ŀ\n");
			char type[20];
			scanf("%s", type);
			for (p = head->next; p->next != NULL; p = p->next) {
				if (strstr(p->type, type))
					printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);
			}
			break;
		case 3:
			printf("������ѧԺ\n");
			char school[20];
			scanf("%s", school);
			for (p = head->next; p->next != NULL; p = p->next) {
				if (strstr(p->school, school))
					printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);

			}
			break;
		case 4:
			x = 0;
			break;
		default:
			printf("��������ȷѡ��\n");
			system("pause");
		}
		system("pause");
	}
}
