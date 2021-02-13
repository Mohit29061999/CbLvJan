#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    //number to be stored from 1 to 10
    int arr[n];   //you should either tell elements of the array
                                             //or its size while declaring

    //to store values in an array
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }

  for(int i=n-1;i>=0;i--){  //you print an array in reverse
      cout << arr[i] << " ";
  }

  //once you write arr[i], this becomes a variable for ith index
}


