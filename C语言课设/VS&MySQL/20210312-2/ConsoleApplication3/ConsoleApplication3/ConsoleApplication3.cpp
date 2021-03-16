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
// STAFF goods_v1.staff
// GOODS goods_v1.goods
// CUSTOMER goods_v1.customer
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
bool chaxun_1(char *);
int StrReplace(char strRes[],const char from[], char to[]);
void StrWhere(char strRes[],const char where[], const char xxx[]);

int main() {
	char zl[200] = "select * from goods_v1.goods";
	int choice;
	char fw[200] = { 0 };
	//初始化
	{
		//初始化连接环境
		if (NULL != mysql_init(&mysql))
			printf("------环境连接成功qwq------\n");
		else
		{
			printf("------环境连接失败T_T------\n");
			return -1;
		}

		//连接mysql服务器(localhost)
		if (!mysql_real_connect(&mysql, HOST, USERNAME, PASSWORD, DBNAME, 3306, NULL, 0))
		{
			printf("------数据库连接失败T_T------\n");
			return -1;
		}
		else
			printf("------数据库连接成功qwq------\n");

		//设置查询字符集
		mysql_query(&mysql, "set names gbk");
	}
	while (1)
	{
		printf("\t您想……？\n");
		printf("\t(1)显示所有商品数据.\t(2)按名称查询商品.\n");
		printf("\t(3)按类型查询商品.\t(4)按日期查询商品.\n");
		printf("\t(5)退出系统.\n\n");
		printf("\t请输入选项前数字:  ");
		scanf("%d", &choice);
		getchar();
		switch(choice) {
			case 1:
				system("cls");
				chaxun_1(zl);
				printf("\n\n\t(按任意键返回)");
				fgets(fw,100,stdin);
				system("cls");
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
				StrWhere(ord, "Name",rep);
				chaxun_1(ord);
				printf("\n\n\t(按任意键返回)");
				fgets(fw, 100, stdin);
				system("cls");
			}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				system("cls");
				printf("请输入1~5中的一个数字哦^-^\n");
				continue;
		}
	}
	
	//指令
	

	//结束
	{
		//释放结果集
		mysql_free_result(res);
		//关闭mysql实例
		mysql_close(&mysql);

		printf("\n------环境关闭成功qwq------\n");
	}
	return 0;
}

bool chaxun_1(char * query) {
	//查询
	if (mysql_real_query(&mysql, query, (unsigned long)strlen(query)))
	{
		printf("------查询失败T_T------\n");
		return false;
	}
	//存储结果集(结构体地址)
	res = mysql_store_result(&mysql);
	if (NULL == res)
	{
		printf("------结果集获取失败T_T------\n");
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
	for (int i = 0; i < num; ++i)
	{
		printf("%-16s", fields[i].name);
	}
	printf("\n");
	//遍历结果集
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < num; i++)
			printf("%-16s", row[i]);
		printf("\n");
	}
	return true;
}

// 将strRes中的t替换为s，替换成功返回1，否则返回0。
int StrReplace(char strRes[],const char from[],const char to[]) {
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
//在基础查询语句"select * from goods_v1.goods"后加上" where 列名称 = "搜索对象""
void StrWhere(char strRes[],const char where[],const char xxx[]) {
	int len = (int)strlen(strRes);
	char str_where[30] = " where # = \"@\"";
	for (int i = 0; i < 16; i++)
		strRes[len + i] = str_where[i];
	StrReplace(strRes, "#", where);
	StrReplace(strRes, "@", xxx);
}