#include <iostream>   //header file has cout defined
using namespace std;   //use standard namespace

//: means comments ie.those section of your code that complier ignores
/*
mutliple line comment
*/



int main(){ //starting point of your code
    int x;
    cin>>x;


    //all of if,else if,else if,else ,only one is true
    if(x==1){
        cout << "First Year";

    }
    else if(x==2){
        cout << "Second Year";
    }
    else if(x==3){
        cout << "Third Year";
    }
    else{
        cout << "Fourth Year";
    }

  int y=6;

    if(y==5){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    //exit statement - program ends here
    return 0;  //0 means program excuetes successfully
}


