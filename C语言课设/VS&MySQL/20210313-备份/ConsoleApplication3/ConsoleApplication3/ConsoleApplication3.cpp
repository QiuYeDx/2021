#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"libmysql")
#include <mysql.h>
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "20011216"
#define DBNAME "goods_v1"
char zl_get_id[50] = "select count(ID) from goods_v1.goods";
// STAFF goods_v1.staff
// GOODS goods_v1.goods
// CUSTOMER goods_v1.customer
//执行一个sql语句, 添删查改的sql语句都可以
//int mysql_query(MYSQL *mysql, const char *query);
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
int MAX_ID = 0;
char MAX_ID_STR[20] = { 0 };
bool chaxun_1(char *);
bool update_id();
int StrReplace(char strRes[],const char from[], const char to[]);
bool insert_1(int *);
void StrWhere(char strRes[],const char where[], const char xxx[]);
void StrOrder(char strRes[], const char xxx[]);
void StrLike(char strRes[], const char xxx[]);
int main() {
	char zl[200] = "select * from goods_v1.goods";
	int choice;
	int flag_while = 1;
	char fw[200] = { 0 };
	//初始化
	{
		//初始化连接环境
		if (NULL != mysql_init(&mysql))
			printf("------系统连接成功------\n");
		else
		{
			printf("\a------系统连接失败------\n");
			return -1;
		}

		//连接mysql服务器(localhost)
		if (!mysql_real_connect(&mysql, HOST, USERNAME, PASSWORD, DBNAME, 3306, NULL, 0))
		{
			printf("\a------数据库连接失败------\n");
			return -1;
		}
		else
			printf("------数据库连接成功------\n");

		//设置查询字符集
		mysql_query(&mysql, "set names gbk");
	}

	//进入主菜单
	while (flag_while)
	{
		printf("\t您想……？\n");
		printf("\t(1)显示所有商品数据.\t(2)按名称查询商品.\n");
		printf("\t(3)按类型查询商品.\t(4)按日期查询商品.\n");
		printf("\t(5)插入商品数据.\t(6)退出系统.\n\n");
		printf("\t请输入选项前数字:  ");
		scanf("%d", &choice);
		getchar();
		switch(choice) {
			case 1:
				system("cls");
				chaxun_1(zl);
				{
					int flag_order = 1;
					while (flag_order)
					{
						printf("\n\n\t输入数据条目或对应序号以进行排序显示(输入#返回):  ");
						char ord[200] = "select * from goods_v1.goods";
						char rep[200] = { 0 };
						scanf("%s", rep);
						getchar();
						system("cls");
						if (rep[0] == '#')
						{
							system("cls");
							flag_order = 0;
						}
						else
						{
							StrOrder(ord, rep);
							chaxun_1(ord);
						}
					}
				}
				break;
			case 2:
			{
				char ord[200] = "select * from goods_v1.goods";
				char rep[200] = { 0 };
				system("cls");
				chaxun_1(zl);
				printf("\n\n请输入欲查询商品的名称:  ");
				scanf("%s", rep);
				getchar();
				system("cls");
				StrLike(ord,rep);
				chaxun_1(ord);
				printf("\n\n\t(按任意键返回)");
				fgets(fw, 100, stdin);
				system("cls");
			}
				break;
			case 3:
			{
				char ord[200] = "select * from goods_v1.goods";
				char rep[200] = { 0 };
				system("cls");
				chaxun_1(zl);
				printf("\n\n请输入欲查询商品的类型:  ");
				scanf("%s", rep);
				getchar();
				system("cls");
				StrWhere(ord, "类型", rep);
				chaxun_1(ord);
				printf("\n\n\t(按任意键返回)");
				fgets(fw, 100, stdin);
				system("cls");
			}
				break;
			case 4:
			{
				char ord[200] = "select * from goods_v1.goods";
				char rep[200] = { 0 };
				system("cls");
				chaxun_1(zl);
				printf("\n\n请输入欲查询商品的日期:  ");
				scanf("%s", rep);
				getchar();
				system("cls");
				StrWhere(ord, "日期", rep);
				chaxun_1(ord);
				printf("\n\n\t(按任意键返回)");
				fgets(fw, 100, stdin);
				system("cls");
			}
				break;
			case 6:	//退出系统
				flag_while = 0;
				break;
			case 5:	//录入数据
			{
				int flag_insert = 1;
				while (1)
				{
					insert_1(&flag_insert);
					if (!flag_insert)
					{
						system("cls");
						break;
					}
					printf("(按下回车键返回)");
					getchar();
					getchar();
					system("cls");
				}
			}
				
				break;
			default:
				system("cls");
				printf("请输入1~6中的一个数字哦^-^\n");
				continue;
		}
	}
	//结束
	{
		//释放结果集
		mysql_free_result(res);
		//关闭mysql实例
		mysql_close(&mysql);
		printf("\n------系统成功退出------\n");
	}
	return 0;
}

// 将strRes中的t替换为s，替换成功返回1，否则返回0。
int StrReplace(char strRes[], const char from[], const char to[]) {
	int i, flag = 0;
	char *p, *ts;
	const char * q;
	for (i = 0; strRes[i]; ++i) {
		if (strRes[i] == from[0]) {
			p = strRes + i;
			q = from;
			while (*q && (*p++ == *q++));
			if (*q == '\0') {
				ts = (char *)malloc(strlen(strRes) + 1);
				strcpy(ts, p);
				strRes[i] = '\0';
				strcat(strRes, to);
				strcat(strRes, ts);
				free(ts);
				flag = 1;
			}
		}
	}
	return flag;
}
//自编万能查询(并输出结果)
bool chaxun_1(char * query) {
	//查询
	if (mysql_real_query(&mysql, query, (unsigned long)strlen(query)))
	{
		printf("\a------查询失败T_T------\n");
		return false;
	}
	//存储结果集(结构体地址)
	res = mysql_store_result(&mysql);
	if (NULL == res)
	{
		printf("\a------结果集获取失败T_T------\n");
		return false;
	}

	// 参数: 调用 mysql_store_result() 得到的返回值
	// 返回值: MYSQL_FIELD* 指向一个结构体
	// 通过查询官方文档, 返回是一个结构体的数组
	// 通过这个函数得到结果集中所有列的名字
	MYSQL_FIELD *mysql_fetch_fields(MYSQL_RES *result);
	// 得到存储头信息的数组的地址
	MYSQL_FIELD* fields = mysql_fetch_fields(res);
	// 得到列数
	int num = mysql_num_fields(res);
	// 遍历得到每一列的列名
	printf("\n+———————————————————————————————————————————————————————————————+\n");
	printf("|");
	for (int i = 0; i < num; ++i)
	{
		printf("%-16s", fields[i].name);
	}
	printf("\b\b|\n+———————————————————————————————————————————————————————————————+\n");
	//遍历结果集
	int flag_row = 0;
	while (row = mysql_fetch_row(res))
	{
		flag_row = 1;
		printf("|");
		for (int i = 0; i < num; i++)
			printf("%-16s", row[i]);
		printf("\b\b|\n");
	}
	printf("+———————————————————————————————————————————————————————————————+\n");
	if (!flag_row)
	{
		system("cls");
		printf("\a没有找到相关商品QAQ");
	}
	return true;
}
//自编数据插入 INSERT INTO table_name(列1，列2，...) VALUES (值1，值2，...)
bool insert_1(int * Flag_insert) {
	char zl[200] = "INSERT INTO goods_v1.goods (ID,名称,类型,库存,售价,进价,日期,销量) VALUES (#,\"$\",\"+\",&,*,-,CURDATE(),0)";
	char MC[40] = { 0 };
	char LX[40] = { 0 };
	char KC[40] = { 0 };
	char SJ[40] = { 0 };
	char JJ[40] = { 0 };
	system("cls");
	printf("请输入：\n商品名称 类型 库存 售价 进价(输入#返回)\n");
	scanf("%s", MC);
	if (MC[0] == '#')
	{
		*Flag_insert = 0;
		return false;
	}
		
	scanf("%s %s %s %s",LX,KC,SJ,JJ);
	if (update_id())
	{
		StrReplace(zl,"#", MAX_ID_STR);
		StrReplace(zl,"$", MC);
		StrReplace(zl,"+", LX);
		StrReplace(zl,"&", KC);
		StrReplace(zl,"*", SJ);
		StrReplace(zl,"-", JJ);
		if (!mysql_query(&mysql, zl))
		{
			system("cls");
			printf("数据录入成功！\n以下是成功录入的数据: \n");
			{	//输出录入的数据
				char ord[200] = "select * from goods_v1.goods";
				char rep[30] = { 0 };
				for (int i = 0; i < strlen(MAX_ID_STR); i++)
					rep[i] = MAX_ID_STR[i];
				StrWhere(ord, "ID", rep);
				chaxun_1(ord);
			}
			return true;
		}
		else
		{
			printf("数据录入失败！(a)\n");
			return false;
		}
	}
	else
	{
		printf("数据录入失败！(b)\n");
		return false;
	}
}
//获取最新MAX_ID值   while (!update_id());
bool update_id() {
	if (mysql_real_query(&mysql, zl_get_id, (unsigned long)strlen(zl_get_id)))
		return false;
	//存储结果集(结构体地址)
	res = mysql_store_result(&mysql);
	if (NULL == res)
		return false;
	//遍历结果集
	int flag_row = 0;
	while (row = mysql_fetch_row(res))
	{
		flag_row = 1;
		sscanf(row[0], "%d", &MAX_ID);
	}
	_itoa(++MAX_ID,MAX_ID_STR,10);
	/*for (int i = 0; i < strlen(row[0]); i++)
		MAX_ID_STR[i] = row[0][i];*/	//ERROR(NEED++)
	if (!flag_row)
		return false;
	return true;
}
//在基础查询语句"select * from goods_v1.goods"后加上" where 列名称 = "搜索对象""
void StrWhere(char strRes[],const char where[],const char xxx[]) {
	int len = (int)strlen(strRes);
	char str_where[30] = " where # = \"@\"";
	for (int i = 0; i < 16; i++)
		strRes[len + i] = str_where[i];
	StrReplace(strRes, "#", where);
	StrReplace(strRes, "@", xxx);
}
//排序
void StrOrder(char strRes[], const char xxx[]) {
	int len = (int)strlen(strRes);
	char str_order[30] = " order by @";
	for (int i = 0; i < 11; i++)
		strRes[len + i] = str_order[i];
	StrReplace(strRes, "@", xxx);
}
//模糊搜索
void StrLike(char strRes[], const char xxx[]) {
	int len = (int)strlen(strRes);
	char str_where[30] = " where 名称 REGEXP '[@]'";
	for (int i = 0; i < 24; i++)
		strRes[len + i] = str_where[i];
	StrReplace(strRes, "@", xxx);
}
