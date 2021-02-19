#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;  //how many elements are there

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];    //what is value of the current element\

    int count[1000001];
    for(int i=0;i<=1000000;i++)
        count[i]=0;    //keep intial count to be zero.

    //step 1: keep a count of number of times an integer is coming
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }

    //step2 : print the number of times an integer is coming starting from 0,1,2,3...
    for(int i=0;i<=1000000;i++){
        int x=count[i];  //how many times i is coming
        for(int j=1;j<=x;j++){
            cout <<i << " ";  //print i integer x times
        }
    }




}

