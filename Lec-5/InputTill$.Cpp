#include <iostream>
using namespace std;


int main(){
    int count =0;  //characters entered till now
    char ch;
    cin>>ch;  //first character entered by the user

    //keep asking user for more input as long as he/she is
    //not entering a $
    while(ch!='$'){
        count++;  //a non-$ character inputed
        cin>>ch;
    }


    cout << count << endl;
}
