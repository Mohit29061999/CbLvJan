#include <iostream>
using namespace std;




int main(){
    //ask the user how many rows i have to print
    int n;
    cin>>n;

    //repeat some task for n rows :we use loop
    int row =1;  //we are printing first row at the start
    while(row<=n){
        //print n-row space
        //write a loop to print n-row space
        int space =1;
        while(space<=n-row){
            cout << " ";
            space=space+1;
        }

        //print increasing numbers
        int no=row;
        //i is storing total numbers printed till now
        int i=1;
        while(i<=row){
            cout << no;
            no=no+1;
            i=i+1;
        }
         cout << i << endl;

        //print decreasing number
        no=2*row-2;
        i=1;
        while(i<=row-1){
            cout << no ;
            no=no-1;
            i=i+1;
        }
        row=row+1;
        cout << endl;
        //cout << '\n';
    }



}
