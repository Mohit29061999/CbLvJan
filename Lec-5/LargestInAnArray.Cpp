#include <iostream>
#include <climits>  //has defination of INT_MAX (Max value an int can take) and INT_MIN(min val an int can take)
using namespace std;


int main(){
     int n;
     cin>>n;

       int arr[n];


     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     int largest =INT_MIN;      //min value that an integer can take
     for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
     }

     cout << largest << endl;




}





