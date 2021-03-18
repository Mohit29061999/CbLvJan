#include <iostream>
using namespace std;

void phoneKeyPad(char a1[],string arr[],int i,char out[]){ //i -for which index i am  fixing char
    //base case
    if(a1[i]=='\0'){
        out[i]='\0';
        cout << out << endl;
        return ;
    }

    int digit=a1[i]-'0';  //to get the integer value of digit so that we can use it for indexing

    //try all char for this digit\
    //2-"abc"
    for(int j=0;j<arr[digit].length();j++){
        //we have fixed the char corresponding to ith digit
        out[i]=arr[digit][j];
        //now recursion will fix rest of the digits
        phoneKeyPad(a1,arr,i+1,out);

    }



}

int main(){
    //to map digits to char
    string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char a1[100];
    cin>>a1;
    char out[100];

    phoneKeyPad(a1,arr,0,out);



}
