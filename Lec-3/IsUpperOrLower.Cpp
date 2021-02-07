#include <iostream>
using namespace std;


int main(){
    //ask the user what is that character
    char c;
    cin>>c;

    if(c>='a' && c<='z')
        cout << "Lower Case";
        //cout << "yes";//won't be a part of if
    else if(c>='A' && c<='Z')
        cout << "Upper Case";
    else
        cout << "Invalid Input";



}
