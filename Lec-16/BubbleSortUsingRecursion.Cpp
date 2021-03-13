#include <iostream>
using namespace std;



void innerLoop(int arr[],int i,int e){
    //base case
    if(i==e)
        return;

    //do the task for ith index
    if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]); //inbuilt swap function

    //call recursion for rest of the array
    innerLoop(arr,i+1,e);
}

void outerLoop(int arr[],int i,int n){ //i is current iteration number
    //base case
    if(i==n-1)
        return;

    //do one iteration of inner loop ,rest will be done by recursion
    innerLoop(arr,0,n-1-i);

    //recursion will do the rest of iteration
    outerLoop(arr,i+1,n);
}

int main(){
  int arr[]={6,4,3,5,2,1};
  int n=6;
  outerLoop(arr,0,n);

  for(int i=0;i<n;i++)
    cout << arr[i] << " ";



}


