#include <iostream>
using namespace std;

int main(){
    int x=5;
    int* p =&x;
    cout << p+1 << endl;
    cout << &x+1 << endl;
}
