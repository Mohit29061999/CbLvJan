#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int m;
    cin>>m;

    int a1[n+m];
    for(int i=0;i<n;i++)
        cin>>a1[i];

        int a2[m];
         for(int i=0;i<m;i++)
        cin>>a2[i];

    int i=n-1;  //current element of a1
    int j=m-1;  //currrent element of a2
    int k=n+m-1;   //where to add current element

    while(i>=0 && j>=0){
        if(a1[i]>=a2[j]){
            a1[k]=a1[i];
            i--;
            k--;
        }
        else{
            a1[k]=a2[j];
            j--;
            k--;
        }
    }

    //add remaining elements
    while(j>=0){
        a1[k]=a2[j];
        j--;
        k--;
    }



    for(int i=0;i<n+m;i++)
        cout << a1[i] << " ";











}



