#include <iostream>
using namespace std;

int main(){
    //ask the user what is the increasing star rows;
    int n;
    cin>>n;

    //print increasing star first;
    for(int row=1;row<=n;row++){
        //print 2*row -1 star
        for(int star =1;star<=row;star++){
            cout << "* ";
        }

        cout << endl;  //to print different rows on different line
    }

    //print decreasing star pattern
        for(int row=1;row<=n-1;row++){
        //print 2*row -1 star
        for(int star =1;star<=(n-row);star++){
            cout << "* ";
        }

        cout << endl;
    }








}






