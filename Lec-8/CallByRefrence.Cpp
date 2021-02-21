#include <iostream>
using namespace std;

//one variable with two name
void update(int &x){  //int &x=n;
x++;
}


int  main(){ ///main is by default called
   //refrence is a nickname to a variable
   /*int x=10;
   int &y =x;  //y is nickname to x; //& is operator to add refrence to a variable
   y++;
   cout << x << endl; */
   int n=10;
   update(n);
  cout << n << endl;


}



