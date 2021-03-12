#include <WinSock2.h>
#include <stdio.h>
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

int main() {
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

	if (mysql_real_query(&mysql, "select * from goods_v1.staff", (unsigned long)strlen("select * from goods_v1.staff")))
	{
		printf("------查询失败T_T------\n");
		return -1;
	}
	res = mysql_store_result(&mysql);
	if (NULL == res)
	{
		printf("------结果集获取失败T_T------\n");
		return -1;
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
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < num; i++)
			printf("%-16s", row[i]);
		printf("\n");
	}
	printf("\n");
	
	//释放结果集
	mysql_free_result(res);
	//关闭mysql实例
	mysql_close(&mysql);

	printf("\n------环境关闭成功qwq------\n");

	return 0;
}
