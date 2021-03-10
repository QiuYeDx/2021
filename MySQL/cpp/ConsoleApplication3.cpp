#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib,"libmysql")
#include <mysql.h>
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "20011216"
#define DBNAME "sakila"
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
int main() {
	if (NULL != mysql_init(&mysql))
		printf("init succeed!\n");
	else
	{
		printf("init failed!\n");
		return -1;
	}
	if (!mysql_real_connect(&mysql, HOST, USERNAME, PASSWORD, DBNAME, 3306, NULL, 0))
	{
		printf("connect failed!\n");
		return -1;
	}
	else
		printf("connect succeed!\n");
	if (mysql_real_query(&mysql, "select * from sakila.actor", (unsigned long)strlen("select * from sakila.actor")))
	{
		printf("mysql_real_query failure!\n");
		return -1;
	}
	res = mysql_store_result(&mysql);
	if (NULL == res)
	{
		printf("mysql_store_result failure!\n");
		return -1;
	}
	while (row = mysql_fetch_row(res))
	{
		printf("%s\t", row[0]);
	}
	mysql_free_result(res);
	mysql_close(&mysql);
	printf("\nclose succeed!\n");


	return 0;
}
