#include <iostream>
using namespace std;


int main(){
 int a=5;
 cout << "value of a: " << a<< endl;
  cout << "address of a: " << &a<< endl;  //a hexadecimal number

  float b=5.5;
   cout << "address of b: " << &b<< endl;

   char c='b';
   cout << "address of c: " <<(float *)&c<< endl;  //we are saying this is the address of float only
  /* float f=10.5;
    char d='a';
    cout << 5+d << endl;
   cout << (int)f << endl;  //explicit typecasting*/
   //char d='abc'; */

}



