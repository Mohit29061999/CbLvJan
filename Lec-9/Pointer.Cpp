#include <iostream>
using namespace std;


int main(){
 int a=5;
 int* p; //define a pointer   //defining a pointer which is storing address of an integer
 p=&a;   //assignment step

  /*int* p =&a;  //initialisation of a pointer
 cout << &a << endl;  //prints the address of a variable
 cout << p << endl;   //print the value of a pointer is address of a */

 //cout << *(&a) << endl;
 //cout << *p << endl;
 // *p = 1;  //changing value of variable using pointer
 //a=a+1;
// *p=*p+1;
(*p)++;  //a++;
  cout << *p << endl;

 //cout << *(p+1) << endl;  //go to next bucket
// cout << &a+1 << endl;



}





