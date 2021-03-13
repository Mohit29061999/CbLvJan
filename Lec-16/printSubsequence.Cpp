#include <iostream>
using namespace std;

void printSub(char arr[],int i,char out[],int j){
    //i is index for which we are taking decision ie.to add it or not
    //j is telling you the position where you add element in current sub
    //base case
    if(arr[i]=='\0'){
        out[j]='\0';
        cout << out << endl;
        return;
    }

    //take decision for ith character
    //case1: include it
    out[j]=arr[i];
    printSub(arr,i+1,out,j+1);

    //case2:not include it
    printSub(arr,i+1,out,j);

}


int main(){
 char arr[100];
 cin>>arr;

 char out[100];  // to store the subsequence
 printSub(arr,)



}



