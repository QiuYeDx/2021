#include <iostream>

using namespace std;

int main() {
    int A, B, a, b;
    cin >> A >> B >> a >> b;

    int min_a=0;
    int min_b=0;

    min_a=A/(2*a);
    if(A%(2*a)>=a)
        min_a++;
    min_b=B/(2*b);
    if(B%(2*b)>=b)
        min_b++;
    cout << min_a*min_b;
    return 0;
}
