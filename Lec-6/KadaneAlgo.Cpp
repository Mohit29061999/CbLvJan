#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int max_s=INT_MIN;   //INT_MIN is min possible value of an interger ie.-infinity
    int curr_s=0;

    int sub_s=0;  //start of current subarray
    int max_s_s;  //start of max_subarray
    int max_s_l;  //length of max subarray

    for(int i=0;i<n;i++){
        //add current element to curr_subarray
        curr_s+=arr[i];
        if(curr_s>max_s){
            max_s= curr_s;
            max_s_s = sub_s;  //change starting index of max_sum
            max_s_l = i-max_s_s+1;

        }
        if(curr_s<0){
            curr_s=0;  //make it empty
            sub_s=i+1;
        }
    }
    cout << max_s << endl;
   //printing the maximum subarray
   for(int i=max_s_s;i<max_s_s+max_s_l;i++)
    cout << arr[i] << " ";


}


