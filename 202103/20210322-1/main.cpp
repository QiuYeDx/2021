#include <iostream> //c++实验1-2
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU{
public:
    CPU(){
        cout << "Construct CPU" << endl;
    }
    ~CPU(){
        cout << "Destruct CPU" << endl;
    }
    CPU(CPU & cpu_tmp){
        cout << "CPU copy constructor" << endl;
    }
private:
    int frequency;
    double voltage;
    CPU_Rank rank;
};
class RAM{
public:
    RAM(){
        cout << "Construct RAM" << endl;
    }
    ~RAM(){
        cout << "Destruct RAM" << endl;
    }
    RAM(RAM & ram_tmp){
        cout << "RAM copy constructor" << endl;
    }
private:

};
class CDROM{
public:
    CDROM(){
        cout << "Construct CDROM" << endl;
    }
    ~CDROM(){
        cout << "Destruct CDROM" << endl;
    }
    CDROM(CDROM & cdrom){
        cout << "CDROM copy constructor" << endl;
    }
private:
};
class Computers{
public:
    Computers(CPU cpu_tmp,RAM ram_tmp,CDROM cdrom_tmp):cpu(cpu_tmp),ram(ram_tmp),cdrom(cdrom_tmp){
        cout << "Construct Computer" << endl;
    }
    ~Computers(){
        cout << "Destruct Computer" << endl;
    }
    Computers(Computers &computers_temp):cpu(computers_temp.cpu),ram(computers_temp.ram),cdrom(computers_temp.cdrom){
        cout << "Computer copy constructor" << endl;
    }
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};
int main() {
    CPU cpu;
    RAM ram;
    CDROM cdrom;
    Computers computers1(cpu,ram,cdrom);
    Computers computers2(computers1);
    return 0;
}
