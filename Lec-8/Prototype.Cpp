#include <iostream>
using namespace std;

//bool isEven(int n);  //write a prototype

bool isOdd();

bool isEven(int n){
    //return n%2==0;
    return isOdd();
}

bool isOdd(){
    return true;
}


int  main(){ ///main is by default called
  if(isEven(4)){
    cout << "Yes" << endl;

  }
  else
    cout << "No" << endl;

}


