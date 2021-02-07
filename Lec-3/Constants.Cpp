#include <iostream>
using namespace std;

//write a macro
#define Pi 3+1//these are constant

//it won't take space
//pi ke as 3 use kar lo


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
cin>>r;  //r is 2

cout << 2*(Pi)*r<< endl;   //they are not solved     2*3+1*2  second case:2*(3+1)*2;


return 0;  //this return 0 is automatically added by complier


}



