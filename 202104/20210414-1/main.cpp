#include <bits/stdc++.h>
using namespace std;
class Tree{
public:
    Tree(int years):ages(years){}
    Tree(){ages=0;}
    void grow(int years){
        ages+=years;
    }
    void age(){
        cout << ages << endl;
    }
private:
    int ages;
};
int main() {
    Tree tree(20);
    tree.age();
    tree.grow(5);
    tree.age();
    return 0;
}
