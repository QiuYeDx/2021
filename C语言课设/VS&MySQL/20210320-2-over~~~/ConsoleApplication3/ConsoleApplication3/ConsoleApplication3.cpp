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
char update_key1[50] = "alter table goods_v1.goods drop ID";
char update_key2[80] = "alter table goods_v1.goods add ID int(11) primary key auto_increment first";
char filename[250] = "C:\\mysql_backup\\backup.sql";
// STAFF goods_v1.staff
// GOODS goods_v1.goods
// CUSTOMER goods_v1.customer
//执行一个sql语句, 添删查改的sql语句都可以
//int mysql_query(MYSQL *mysql, const char *query);
//UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
int MAX_ID = 0;
char MAX_ID_STR[20] = { 0 };
bool chaxun_1(char *);
bool update_id();
int StrReplace(char strRes[],const char from[], const char to[]);
bool insert_1(int *);
bool update_price(int ID, char* new_price);
bool delete_ID(int ID);
bool buy_goods(int ID, int num);
bool backup();
bool recover();
void StrWhere(char strRes[],const char where[], const char xxx[]);
void StrOrder(char strRes[], const char xxx[]);
void StrLike(char strRes[], const char xxx[]);
int main() {
	char zl[200] = "select * from goods_v1.goods";
	int choice;
	int flag_while = 1;
	int flag_7 = 1;
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
		printf("\t\b\b>>您想……？\n");
		printf("\t(1)显示所有商品数据.\t(2)按名称查询商品.\n");
		printf("\t(3)按类型查询商品.  \t(4)按日期查询商品.\n");
		printf("\t(5)上架商品.        \t(6)售出商品\n");
		printf("\t(7)数据备份与恢复.  \t(8)退出系统.\n\n");
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
				printf("\n\n\t\b\b>>请输入欲查询商品的名称:  ");
				scanf("%s", rep);
				getchar();
				system("cls");
				StrLike(ord,rep);
				if (!chaxun_1(ord))
				{
					Sleep(2000);
					system("cls");
					break;
				}
				int flag_order = 1;
				while (flag_order)
				{
					printf("\n\n\t\b\b>>请选择操作(输入#返回):  \n\t(1)修改售价.\t(2)删除商品.\n\t");
					char ord[200] = "select * from goods_v1.goods";
					char rep[200] = { 0 };
					scanf("%s", rep);
					getchar();
					if (rep[0] == '#')
					{
						system("cls");
						flag_order = 0;
					}
					else if(rep[0] == '1')
					{
						int ID;
						char NewPrice[20] = { 0 };
						printf("\t\b\b>>请输入待修改商品的相关数据: \n\tID: ");
						scanf("%d",&ID);
						printf("\t售价: ");
						scanf("%s", NewPrice);
						update_price(ID, NewPrice);
					}
					else if (rep[0] == '2') 
					{
						int ID;
						printf("\t请输入待删除商品的ID: \n\tID: ");
						scanf("%d", &ID);
						delete_ID(ID);
					}
				}
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
			case 8:	//退出系统
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
			case 6:
			{
				int ID, num;
				system("cls");
				chaxun_1(zl);
				printf("\t\b\b>>请输入将要售出的商品的相关信息：\n\tID: ");
				scanf("%d", &ID);
				printf("\t数量: ");
				scanf("%d", &num);
				if (!buy_goods(ID, num))
				{
					Sleep(2500);
					system("cls");
				}

			}
				break;
			case 7: 
				flag_7 = 1;
				while(flag_7)
			{
				int choice;
				printf("\t\b\b>>请选择: \n");
				printf("\t(1)数据备份.\n\t(2)数据恢复.\n\t(3)返回.\n\t");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
				{
					backup();
					flag_7 = 0;
				}
					break;
				case 2:
				{
					recover();
					flag_7 = 0;
				}
				break;
				case 3:
					flag_7 = 0;
					system("cls");
					break;
				default:
					flag_7 = 1;
					printf("\n[请输入1-3以进行选择]\n");
					system("cls");
					break;
				}
			}
				break;
			default:
				system("cls");
				printf("\t[请输入1-8中的一个数字哦]\n");
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
		printf("\a\t[查询失败---请输入合法数据]\n");
		return false;
	}
	//存储结果集(结构体地址)
	res = mysql_store_result(&mysql);
	if (NULL == res)
	{
		printf("\a\t[结果集获取失败]\n");
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
		printf("\a\t[没有找到相关商品]\n");
		return false;
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
//更新售价
bool update_price(int ID, char* new_price) {
	char zl[250] = "UPDATE goods_v1.goods SET 售价 = # WHERE ID = $";
	char str_ID[40] = { 0 };
	_itoa(ID, str_ID, 10);
	StrReplace(zl, "#", new_price);
	StrReplace(zl, "$", str_ID);
	if (!mysql_query(&mysql, zl))
	{
		system("cls");
		printf("\t[数据更新成功]\n以下是成功更新的数据: \n");
		{	//输出更新的数据
			char ord[200] = "select * from goods_v1.goods";
			StrWhere(ord, "ID", str_ID);
			chaxun_1(ord);
		}
		return true;
	}
	else
	{
		printf("\t[数据更新失败]\n");
		printf("\n错误代码:%s", zl);
		return false;
	}
	return true;
}
//删除商品
bool delete_ID(int ID) {
	char zl[250] = "DELETE FROM goods_v1.goods WHERE ID = #";
	char str_ID[40] = { 0 };
	_itoa(ID, str_ID, 10);
	printf("%d --- %s", ID, str_ID);
	StrReplace(zl, "#", str_ID);
	if (!mysql_query(&mysql, zl))
	{
		system("cls");
		printf("\t[商品删除成功]\n");
		mysql_query(&mysql, update_key1);
		mysql_query(&mysql, update_key2);
		return true;
	}
	else
	{
		printf("\t[商品删除失败]\n");
		printf("\t错误代码:%s", zl);
		return false;
	}
	return true;
}
//售出商品
bool buy_goods(int ID, int num) {
	char zl_1[250] = "update goods_v1.goods set 库存 = 库存 - # where ID = $";
	char zl_2[250] = "update goods_v1.goods set 销量 = 销量 + # where ID = $";
	char str_ID[40] = { 0 };
	char str_num[40] = { 0 };
	_itoa(ID, str_ID, 10);
	_itoa(num, str_num, 10);
	StrReplace(zl_1, "$", str_ID);
	StrReplace(zl_1, "#", str_num); 
	StrReplace(zl_2, "$", str_ID);
	StrReplace(zl_2, "#", str_num);
	if (!mysql_query(&mysql, zl_1) && !mysql_query(&mysql,zl_2))
	{
		system("cls");
		printf("\t[商品售出成功]\n以下是成功更新的数据: \n");
		{	//输出更新的数据
			char ord[200] = "select * from goods_v1.goods";
			StrWhere(ord, "ID", str_ID);
			chaxun_1(ord);
		}
		return true;
	}
	else
	{
		printf("\n\t[商品售出失败]\n");
		printf("\t###请检查库存是否充足###\n\n");
		//printf("\n错误代码:%s\n%s", zl_1,zl_2);
		return false;
	}
	return true;
}
//数据备份
bool backup() {
	if (remove(filename) != 0)
	{
		printf("\t[备份文件更新失败]\n");
	}
	char zl[300] = "select * from goods_v1.goods INTO OUTFILE 'C:\\\\mysql_backup\\\\backup.sql'";
	if (!mysql_query(&mysql, zl))
	{
		system("cls");
		printf("\t[数据备份成功]\n");
		return true;
	}
	else
	{
		printf("\t[数据备份失败]\n");
		printf("\n\t\b\b>>错误代码:%s\n", zl);
		return false;
	}
	return true;
}
//数据恢复
bool recover() {
	char zl1[300] = "delete from goods_v1.goods;";
	char zl2[300] = "LOAD DATA INFILE 'C:\\\\mysql_backup\\\\backup.sql' INTO TABLE goods_v1.goods";
	mysql_query(&mysql, zl1);
	if (!mysql_query(&mysql,zl2))
	{
		system("cls");
		printf("\t[数据恢复成功]\n");
		return true;
	}
	else
	{
		printf("\t[数据恢复失败]\n");
		return false;
	}
	return true;
}
