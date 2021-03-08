#include <iostream>
using namespace std;

bool isArraySorted(int arr[],int n,int index){  //index is index which we are comparing
       //base case: if it is last index
       if(index==n-1){
        return true;

       }

       if(arr[index]>arr[index+1])
       return false;

        //index element is correct
       return isArraySorted(arr,n,index+1);


}




int main(){
   int arr[]={4,4,4,4,4};
   int n=5;
   if(isArraySorted(arr,n,0)==true)
    cout << "YES" << endl;
   else
    cout << "NO" << endl;
}


