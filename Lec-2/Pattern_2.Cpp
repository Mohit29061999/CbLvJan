#include <iostream>
using namespace std;




int main(){
    //ask the user how many rows i have to print
    int n;
    cin>>n;

    //do some task for n rows
    //we will need a loop for that
    int row=1;
    //first no to be printed is 1
    int no=1;
    while(row<=n){
        //do some task for this row
        int i=1;
        while(i<=row){
            cout << no << " ";
            i=i+1;
            no=no+1;
        }





        row=row+1;
        cout << endl;

    }





}
