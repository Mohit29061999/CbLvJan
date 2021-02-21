#include <iostream>
using namespace std;

//two different variable and copying value of one in another
int update(int n){  //copying the value of n in a new variable x
                      //it is call by value

                      //int n=10;  //two variable with same scope
            n++;
         return n;
}


int  main(){ ///main is by default called
  int n=5;
  update(n); //n is 6 in this case

  cout << "n is: " << n << endl;
}


