#include <iostream>
using namespace std;

int*  createArray(int n){
   /* int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=0;
    return arr;  ///return address of the base element ie.0th index
    ///this has scope till function only
    ///so after return statement arr doesn't exist and can't return it's address */

     int *arr =new int[n];
    for(int i=0;i<n;i++)
        arr[i]=i+1;
   // delete []arr;
    return arr;

}


int main(){
   int *a=createArray(10);
   for(int i=0;i<10;i++)
    cout << a[i] << " ";

   // delete []a;

    /* for(int i=0;i<10;i++)
    cout << arr[i] << " "; */



}

