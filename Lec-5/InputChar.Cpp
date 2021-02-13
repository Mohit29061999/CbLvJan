#include <iostream>
using namespace std;


int main(){
    int count =0;  //characters entered till now
    char ch;
   // cin>>ch;  //first character entered by the user
   ch = cin.get();   //cin ignores white space while get deoesn't

    //keep asking user for more input as long as he/she is
    //not entering a $
    while(ch!='$'){

        count++;  //a non-$ character inputed
       // cin>>ch;
        ch = cin.get();
    }
    //char c='95';  //every digit from 0 to 9 have an ascii code
   // cout << c << endl;
    cout << count << endl;
}

