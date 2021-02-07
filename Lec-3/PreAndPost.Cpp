#include <iostream>
using namespace std;


int main(){
    int a=10;
    int b;
    int c;

    b=a++;   //post increment
    a=10;

    c=++a;   //pre increment

    cout << b << " " << c << endl;          //b== 10     && c== 11



}
