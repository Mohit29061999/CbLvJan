#include <iostream>
using namespace std;


int main(){
    char a1[100];
    cin>>a1;

    char a2[100];
    cin>>a2;

    int f1[26]={0}; //to store freq of characters in string 1
    int f2[26]={0};  //to store freq of characters in string 2

    //travel through first string and keep changing count of characters
    for(int i=0;a1[i]!='\0';i++){
        int x=a1[i]-'a'; //to map characters to index
        f1[x]++;
    }

    //travel through second string and keep changing count of characters
    for(int i=0;a2[i]!='\0';i++){
        int x=a2[i]-'a'; //to map characters to index
        f2[x]++;
    }

    bool equal = true;  //assuming strings to be permutation
    //go through each characters and check if count is same in both the strings or not
    for(int i=0;i<26;i++){
        if(f1[i]!=f2[i]){
            //count of current characters is different in both the strings
            equal = false;
            break;
        }
    }

    if(equal)
        cout << "permutation" << endl;
    else
        cout << "not a permutation" << endl;




}
