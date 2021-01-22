#include <iostream>    //P1321 单词覆盖还原   1/1 AC
#include <string>
/*题目描述
一个长度为 l(3\le l\le255)l(3≤l≤255) 的字符串中被反复贴有 boy 和 girl 两单词，后贴上的可能覆盖已贴上的单词（没有被覆盖的用句点表示），最终每个单词至少有一个字符没有被覆盖。问贴有几个 boy 几个 girl？

输入格式
一行被被反复贴有boy和girl两单词的字符串。

输出格式
两行，两个整数。第一行为boy的个数，第二行为girl的个数。*/
using namespace std;

int main() {
    string str;
    int boy=0,girl=0;
    int pt;

    getline(cin,str);
    while(~str.find("boy"))
    {
        pt=(int)str.find("boy");
        boy++;
        str=str.substr(0,pt)+"..."+str.substr(pt+3,str.length()-pt);
    }
    while(~str.find("girl"))
    {
        pt=(int)str.find("girl");
        girl++;
        str=str.substr(0,pt)+"...."+str.substr(pt+4,str.length()-pt);
    }
    while(~str.find("bo"))
    {
        pt=(int)str.find("bo");
        boy++;
        str=str.substr(0,pt)+".."+str.substr(pt+2,str.length()-pt);
    }
    while(~str.find("oy"))
    {
        pt=(int)str.find("oy");
        boy++;
        str=str.substr(0,pt)+".."+str.substr(pt+2,str.length()-pt);
    }



    while(~str.find("gir"))
    {
        pt=(int)str.find("gir");
        girl++;
        str=str.substr(0,pt)+"..."+str.substr(pt+3,str.length()-pt);
    }
    while(~str.find("irl"))
    {
        pt=(int)str.find("irl");
        girl++;
        str=str.substr(0,pt)+"..."+str.substr(pt+3,str.length()-pt);
    }
    while(~str.find("gi"))
    {
        pt=(int)str.find("gi");
        girl++;
        str=str.substr(0,pt)+".."+str.substr(pt+2,str.length()-pt);
    }
    while(~str.find("ir"))
    {
        pt=(int)str.find("ir");
        girl++;
        str=str.substr(0,pt)+".."+str.substr(pt+2,str.length()-pt);
    }
    while(~str.find("rl"))
    {
        pt=(int)str.find("rl");
        girl++;
        str=str.substr(0,pt)+".."+str.substr(pt+2,str.length()-pt);
    }
    while(~str.find('g'))
    {
        pt=(int)str.find('g');
        girl++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('i'))
    {
        pt=(int)str.find('i');
        girl++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('r'))
    {
        pt=(int)str.find('r');
        girl++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('l'))
    {
        pt=(int)str.find('l');
        girl++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('b'))
    {
        pt=(int)str.find('b');
        boy++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('o'))
    {
        pt=(int)str.find('o');
        boy++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    while(~str.find('y'))
    {
        pt=(int)str.find('y');
        boy++;
        str=str.substr(0,pt)+"."+str.substr(pt+1,str.length()-pt);
    }
    cout << boy << endl << girl;
    return 0;
}
