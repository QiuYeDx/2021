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
/*建立与运动项目相同的字符数组，用来储存项目，而后，建立多个链表，链表需要在主函数中建立，用来保存不同的项目，头节点保存项目信息*/
int main()
{
	system("color B9");
	Animation();
	ShowTime();
	Login();
	Node *head = NULL;
	head = load();
	if (head == NULL) {
		printf("没有本地数据，请输入比赛结果\n");
		head = Lcreate();
	}
	system("cls");
	system("color f0");
	while (1) {
		system("cls");
		ShowTime();
		printf("\t\t\t\t\t\t  请输入选项\n\n\n\n");
		printf("\t*\t1 : 添加学生成绩\n\n");
		printf("\t*\t2 : 显示输入结果\n\n");
		printf("\t*\t3 : 显示比赛排名\n\n");
		printf("\t*\t4 : 查找\n\n");
		printf("\t*\t5 : 清空比赛信息\n\n");
		printf("\t*\t6 : 退出\n\n");

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
				printf("无法清空数据，初始化失败！\n");
				system("pause");
			}
			break;
		case 6:
			eq();
			break;
		default:
			printf("请输入正确的选项\n");
			system("pause");
		}
	}
	system("cls");
	ArrayLdestroy(head, 1);
	system("pause");
	return 0;
}
#include "student.h"//放在首位
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
		printf("无法创建节点！\n");
		system("pause");
		return 0;
	}
	head->next = NULL;
	return head;
}
student Lcreate()
{
	Node *head, *tail, *nnode;//head为链表头指针，tail为尾指针，nnode为中间处理的指针
	FILE *result;
	if ((result = fopen("D:\\ACYTXX\\result.txt", "a")) == NULL) { //判断是否能找到resul.txt
		printf("无法保存！\n");
		system("pause");
		fclose(result);
		return NULL;
	}
	char name_[20], sex_[10], school_[20], type_[20];
	int n = 0;
	double grade_;
	if ((head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("无法创建链表，程序退出\n");
		system("pause");
		exit(-1);
	}
	head->next = NULL;
	tail = head;
	printf("请依次输入姓名，性别，学院，比赛项目，成绩，EOF结束输入\n");//输入比赛项目基本信息并填充到result.txt文件中
	while (scanf("%s%s%s%s%lf", name_, sex_, school_, type_, &grade_) != EOF)
	{
		++n;
		if ((nnode = (Node *)malloc(sizeof(Node))) == NULL)
		{
			printf("无法创建链表，程序退出\n");
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
		fprintf(result, "%-10s%-7s%-15s%-15s%-7g\n", nnode->name, nnode->sex, nnode->school, nnode->type, nnode->grade);//在文件中记录
		tail->next = nnode;
		tail = nnode;
	}
	head->num = n;
	fclose(result);
	return head;
}
student LfindTail(student head) {		//找到尾指针
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
void Lconnect(student head, student newhead) {		//建立链表，将节点连接起来
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
		printf("无法打开数据文件，没有本地数据！\n");
		system("pause");
		return NULL;
	}
	if ((head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("无法创建链表，程序退出\n");
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
			printf("无法创建链表，程序退出\n");
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
	head->grade = sum;		//统计总分
	head->next = NULL;		//主链表只剩下头节点
}
int Lproject_num(student head) {		//按照项目类型区分
	student p;
	int j = 0, n = 0;
	for (p = head->next; p != NULL; p = p->next) {
		for (j = 0; j <= n; ++j) {
			if (!strcmp(p->type, gametype[j]))
				break;
		}			//改回字符数组，保存，将数组的大小记录.
		if (j > n)
			strcpy(gametype[--j], p->type), ++n;
	}
	return n;		//返回项目的数量。
}
int Lschool_num(student head) {		//按照学院区分
	student p;
	int j = 0, n = 0;
	for (p = head->next; p != NULL; p = p->next) {
		for (j = 0; j <= n; ++j) {
			if (!strcmp(p->school, schooltype[j]))
				break;
		}			//改回字符数组，保存，将数组的大小记录.
		if (j > n)
			strcpy(schooltype[--j], p->school), ++n;
	}
	return n;		//返回项目的数量。
}
void ShowTime() {
	char *wday[] = { "星期日","星期一","星期二","星期三","星期四","星期五","星期六" };
	time_t t;
	struct tm *p;
	t = time(NULL);
	p = gmtime(&t);
	printf("\n%d年%2d月%2d日", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %s ", wday[p->tm_wday]);
	printf("%02d:%02d:%02d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);
}
void Delay(int ms)
{
	int i, j;
	for (i = ms; i>0; i--)
		for (j = 100000; j>0; --j);//自定义delay函数，延迟时间，显示动画

}
void Animation()
{
	system("cls");
	system("color Bc");
	printf("\n\n\t\t\t欢");
	Delay(5000);
	system("cls");
	system("color Ba");
	printf("\n\n\t\t\t\t迎\t");
	Delay(5000);
	system("cls");
	system("color Bd");
	printf("\n\n\t\t\t\t\t使\t");
	Delay(5000);
	system("cls");
	system("color B9");
	printf("\n\n\t\t\t\t\t\t用\t");
	system("cls");
	printf("\n\n\t\t\t欢\t迎\t使\t用");
	printf("\n\n\t\t\t东北大学运动会成绩记录系统\n");
	Delay(3000);
}
void Login()
{
	system("cls");
	char c_password[27], c_ori_code[27];
	FILE *fp, *ac;
	int i, x;
	if ((fp = fopen("D:\\ACYTXX\\p", "rb")) == NULL) {		//检测是否初次登陆
		if (_mkdir("D:\\ACYTXX") == -1) {
			printf("初始化失败！\n\n");
			system("pause");
			exit(1);
		}
		printf("\n\t\t\t\t  初次登陆，请设置初始密码\n\n");
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
	printf("\n\t\t\t\t\t\t  请输入密码\n");

	for (x = 5; x>0; x--) {
		printf("\n\t你还有%d次机会\n", x);
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
			printf("\n\t\t\t\t\t\t 密码错误，请重新输入:\n");
		}
		else
			return;
	}
	exit(1);
	return;
}
void ArrayLdestroy(student head, int n) {		//这个函数没有问题，问题出在分类时，最后一个节点没有指向NULL
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
	printf("\n\n\n\n\n\t\t\t\t\t\t    退出？\n\n\t\t\t\t\t\t  'y' or 'n'\n\n\n");
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
		printf("%s的前六名为\n\n", (subhead + i)->next->type);
		Ldisplay(subhead + i, 6), printf("\n\n");
	}
	ArrayLdestroy(subhead, num);
	//统计每个学院的成绩，先将学生按照学院区分，再统计，结果储存在每个学院头节点的double里
	head = load();
	int num2 = 0;
	num2 = Lschool_num(head);
	Node *subhead2 = (Node*)malloc(num2 * sizeof(Node));
	for (int i = 0; i < num2; ++i) {
		(subhead2 + i)->next = NULL;
		(subhead2 + i)->grade = 0;
	}
	Distinct_stu2(head, subhead2, num2);
	for (int i = 0; i < num2; ++i)		//数组的冒泡排序
		for (int j = num2 - 1; j > i; --j) {
			if ((subhead2 + j)->grade >(subhead2 + j - 1)->grade) {
				Node *temp;
				temp = (Node *)malloc(sizeof(Node));
				*temp = *(subhead2 + j);
				*(subhead2 + j) = *(subhead2 + j - 1);
				*(subhead2 + j - 1) = *temp;
			}
		}
	printf("各代表队的总分前三名为：\n\n");
	for (int i = 0; i < 3; ++i)
		printf("\t%s代表队的总分为%g\n\n", (subhead2 + i)->next->school, (subhead2 + i)->grade);
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

	head->next = NULL;		//主链表只剩下头节点
}
void Search(student head) {
	head = load();
	int x = 1;
	while (x) {
		system("cls");
		ShowTime();
		printf("\t\t\t\t\t\t  请输入选项\n\n\n\n");
		printf("\t*\t1 : 按姓名查找\n\n");
		printf("\t*\t2 : 按比赛项目查找\n\n");
		printf("\t*\t3 : 按学院查找\n\n");
		printf("\t*\t4 : 返回上层菜单\n\n");
		int n = 0;
		scanf("%d", &n);
		student p;
		switch (n) {
		case 1:
			printf("请输入姓名\n");
			char name[20];
			scanf("%s", name);
			for (p = head->next; p->next != NULL; p = p->next) {
				if (strstr(p->name, name))
					printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);
			}
			break;
		case 2:
			printf("请输入比赛项目\n");
			char type[20];
			scanf("%s", type);
			for (p = head->next; p->next != NULL; p = p->next) {
				if (strstr(p->type, type))
					printf("%-10s%-7s%-15s%-15s%-7g\n", p->name, p->sex, p->school, p->type, p->grade);
			}
			break;
		case 3:
			printf("请输入学院\n");
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
			printf("请输入正确选项\n");
			system("pause");
		}
		system("pause");
	}
}
