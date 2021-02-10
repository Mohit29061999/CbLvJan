#include <iostream>
using namespace std;


//global variable that exists everywhere
int x=10;   //variable exists till the end of the code
int main(){

    //scope of a variable means for how long that variable exists

    //we can have two variable with same name and different scope
     bool b=true;
     int x=5;

     // int x=10;  this is not allowed
    // cout << x << endl;
    //cout << x << endl;
     //if(b){
        //int x=1;

       // x++;
         //varible only exists till it's opening curly braces to ending curly braces
 // cout << x << endl;
   //  }

  cout << ::x << endl;     //this x to be global variable then what to do?



//here x dies
  //cout << x << endl;



}







