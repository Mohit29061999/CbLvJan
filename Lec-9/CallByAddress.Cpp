#include <iostream>
using namespace std;

void update(int *n){  //to store address of a variable
    (*n)++;
    //n++;
}

int main(){
  int x=5;
  update(&x);  //changes are staying here
  cout << x << endl;

}







