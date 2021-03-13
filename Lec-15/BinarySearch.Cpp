#include <iostream>
using namespace std;

//recursive solution for binary search
void bs(int arr[],int s,int e,int x){//x is value to be searched
    //base case
    if(s>e){ //no elements are left to be searched
        cout << -1 << endl;
        return;
    }

    int mid =(s+e)/2; //middle index
    if(arr[mid]==x){
        cout << mid +1 << endl; //1-based indexing
        return;
    }

    if(arr[mid]>x){
        //go to left ie. now e =mid-1;
        bs(arr,s,mid-1,x);
    }
    else{
        //middle element is smaller
         bs(arr,mid+1,e,x);
    }
}

int main(){
  int arr[]={1,2,3,4,5,6};
  int n=6;
  int x=10;
 /* int s=0;
  int e=n-1;
  while(s<=e){
     int mid =(s+e)/2; //middle index
     if(arr[mid]==x){
        cout << mid+1 ;  //1-based indexing
        return 0;

     }
     else if(arr[mid]>x){
        //go to left
        e=mid-1;
     }
     else
        s=mid+1;  //middle element is smaller
  }
*/
 // cout << -1 << endl;
 bs(arr,0,n-1,x);

}
