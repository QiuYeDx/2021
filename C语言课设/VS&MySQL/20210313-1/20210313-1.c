#include <stdio.h>

int main(){
	char str[20]="12";
	int test=0;
	sscanf(str,"%d",&test);
	printf("%d",test);
	return 0;
}
 
