#include <iostream>
using namespace std;

//void :a function not returning anything
//function to check if a number is even or not
//function is defined
void SayHello(){
    cout << "Hello World" << endl;
}

void isEven1(){
    int n;
    cin>>n;
    if(n%2==0){
        cout << "It is Even from even1";
    }
    else
      cout << "It is Odd from even1";

    cout << endl;

}

bool isEven2(int n){

    if(n%2==0)
        return true;
    else
        return false;
}

int  main(){ ///main is by default called
// SayHello(); ///calling of a function ,function will exceute only after calling
int n=4;
isEven1();

    if(isEven2(n)){
    cout << "It is Even from even2";
}
else
    cout << "It is Odd from Even2";
   return 0;

}

