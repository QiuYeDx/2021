#include"head.h"


int main()
{
    system("color 3F");
   
    system("color 3F");
    int login_status = login();
    
    while (1)
    {
        if (1 == login_status)
        {
            gotoMainmenu();
        }
    }
    return 0;
}


