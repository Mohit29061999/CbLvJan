#include <iostream>
using namespace std;

//write a macro
#define Pi 3 //these are constant
#define Pi 4

//if we define two macros with same name it will take the most recent one


int main(){

//const int x;  //this will give error constant must be intialised
//x=5;

/*const int x=5;
//x++;   //we are changing x here x=x+1;
int b=x+1;
cout << "b is " << b << endl;
cout << x << endl;
//x=10;  //you can't change value of a constant
//cout << x << endl; */

int r;
cin>>r;

cout << 2*Pi*r<< endl;





}



