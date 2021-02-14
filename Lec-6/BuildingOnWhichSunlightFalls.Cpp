#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int max_h=INT_MIN;
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_h){
            count++;
            cout << i+1 << " ";
            max_h=arr[i];

        }
    }

    cout << endl;

    cout << count << endl;











}



