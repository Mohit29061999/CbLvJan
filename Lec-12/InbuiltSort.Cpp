#include <iostream>
#include <algorithm>  //header file for sort
using namespace std;


bool compare(int a,int b){
    //true means that don't swap elements
    //false means swap
   // cout << a << " " << b << endl;
    return a>b;  //for decreasing order
   //return a<b;  //for increasing order
}

int main(){



  int a[]={1,0,-1,-5,6,9,8,11,3,6};
  int n=sizeof(a)/sizeof(a[0]);


  for(int i=0;i<n;i++)
    cout << a[i] << " ";

  //by default it is increasing order
  sort(a,a+n,compare);  //pass array starting point address to this function and ending point address of the array
  //sort everything before ending point

  for(int i=0;i<n;i++)
    cout << a[i] << " ";


  }










