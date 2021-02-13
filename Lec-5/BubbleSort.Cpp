#include <iostream>
using namespace std;


int main(){
     int n;
     cin>>n;

       int arr[n];


     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     //do n-1 iteration
     for(int i=0;i<n-1;i++){
            bool swap =false;  //whether i have swapped or not in current iteration
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){  //comparing jth value to its adjacent right value
                //swap them ie.a[j] and a[j+1]
                //arr[j] = x and arr[j+1] =y;
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];

                swap = true;   // i have swapped in current iteration
            }
        }

        //check if swap is false , that means we didn't swapped in current iteration
        //that means array is sorted
        if(swap == false)
            break;
     }

     for(int i=0;i<n;i++){
        cout << arr[i] << " ";
     }


}




