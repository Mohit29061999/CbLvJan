#include <iostream>
using namespace std;

/*void printNo(int no,int n){  //no is the no in my hand
    //base case
    if(no==n){
        cout << no ;
        return;  //return alone means to exit the function
    }

    cout << no << " "; //print the number in my hand
    printNo(no+1,n);

} */

void printReverse(int no,int n){  //no is the no in my hand
    //base case
    if(no==n){
        cout << no  << " ";
        return;  //return alone means to exit the function
    }

     printReverse(no+1,n);
    cout << no << " "; //print the number in my hand
}

int main(){
    int n;
    cin>>n;
    //printNo(1,n);
    printReverse(1,n);
}

