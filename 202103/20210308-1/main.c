#include <stdio.h>
#include <windows.h>
#include <time.h>
DWORD _stdcall xiancheng(LPVOID lpvoid){
    int i=0;
    time_t timer;
    while(1){
        timer=time(NULL);
        printf("The current time is: %s\n",asctime(localtime(&timer)));
        Sleep(1);
    }
}
void main() {
    int i=0;
    CreateThread(NULL,0,xiancheng,NULL,0,NULL);
    for(;;);
}
