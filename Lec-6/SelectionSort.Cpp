#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n-1;i++){  //place correct value at every index except last one
        int min_i=i;
        //find the min of remaining array
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_i]){
                min_i = j;
            }
        }

        //swap value at ith index with min_i
      //  if(min_i !=i){
        int temp=arr[i];
        arr[i]=arr[min_i];
        arr[min_i]=temp;
      //  }

    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}

