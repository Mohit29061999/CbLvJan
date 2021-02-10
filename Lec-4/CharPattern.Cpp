#include <iostream>
using namespace std;


int main(){
    //ask the user what is n
    int n;
    cin>>n;

    //do somthing for n rows
    for(int i=1;i<=n;i++){  //just repeat the task for n rows
        //do the task for ith row
        //print increasing char first
        char c='A';
        //print n-i+1 char
        for(int j=1;j<=n-i+1;j++){
            cout << c << " ";
            c++;
        }

        c--;  //since we stop at one value ahead
      //for decreasing char
      for(int j=1;j<=n-i+1;j++){
        cout << c << " ";
        c--;
      }

        //go to next line
        cout << endl;


   }





}




