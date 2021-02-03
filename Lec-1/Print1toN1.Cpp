#include <iostream>   //header file has cout defined
using namespace std;   //use standard namespace

//: means comments ie.those section of your code that complier ignores
/*
mutliple line comment
*/



int main(){ //starting point of your code

    int n;
    cin>>n;

    //loop here
    int x=1;  //initialisation
    while(x<=n){
        //do something
        cout << x << endl;  //endl is used to go to next line
        //updation step
        x=x+1;
    }


    //exit statement - program ends here
    return 0;  //0 means program excuetes successfully
}



