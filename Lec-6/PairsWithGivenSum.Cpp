#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

        int target;
        cin>>target;

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

    int left=0;
    int right =n-1;
    while(left<right){ //as long as there are atleast 2 elements
        int sum=arr[left]+arr[right];
        //case 1:sum<target
        if(sum<target)
            left++;
        else if(sum>target)
            right--;
        else{
            //sum is equal to target
            cout << arr[left] << " " << arr[right] << endl;
            left++;
            right--;
        }

        }







}


