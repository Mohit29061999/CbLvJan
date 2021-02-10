#include <iostream>
using namespace std;


int main(){
    //ask the user what is the increasing star rows;
    int n;
    cin>>n;

    //print increasing star first;
    for(int row=1;row<=n;row++){
        //print n-row spaces
        for(int space =1;space <=n-row;space++){
            cout << " ";
        }

        //print 2*row -1 star
        for(int star =1;star<=2*row-1;star++){
            cout << "*";
        }

        cout << endl;
    }

    //print decreasing star pattern

        for(int row=1;row<=n-1;row++){
        //print row spaces
        for(int space =1;space <=row;space++){
            cout << " ";
        }

        //print 2*row -1 star
        for(int star =1;star<=2*(n-row)-1;star++){
            cout << "*";
        }

        cout << endl;
    }








}





