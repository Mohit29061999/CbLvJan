#include <iostream>
using namespace std;

int ans =0;

void merge(int arr[],int n,int s,int mid ,int e){
    int n1=mid-s+1;  //to calculate length of left half
    int l[n1];
    int n2=e-mid;    ///to calculate length of right half ie. e-(mid+1)+1 = e-mid
    int r[n2];

    //copy elements from left half in l array
    for(int i=0;i<n1;i++)
        l[i]=arr[i+s];

    //copy elements from right half in r array
    for(int i=0;i<n2;i++)
        r[i]=arr[i+mid+1];

    int i=0; //element of first array ie.l
    int j=0; //element of right array ie.r
    int k=s;  //position where current element should be added in final array

    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
           ans+=(n1-i);
            arr[k]=r[j];
            j++;

        }
        k++;
    }

    //add remaining elements of l array
    while(i<n1){
         arr[k]=l[i];
            i++;
            k++;
    }

    //add remaining elements of r array
    while(j<n2){
         arr[k]=r[j];
            j++;
            k++;
    }



}


void mergeSort(int arr[],int n,int s,int e){
    //base case
    if(s==e)
        return; //size 1 array is already sorted

    int mid=(s+e)/2;  //divide the array in two half

    //sort the left part
    mergeSort(arr,n,s,mid);

    //sort the right part
    mergeSort(arr,n,mid+1,e);

    merge(arr,n,s,mid,e); //we have two arrays ie. s to mid and mid+1 end

}

int main(){
  int arr[]={6,4,3,5,2,1};
  int n=6;
  mergeSort(arr,n,0,n-1);
  for(int i=0;i<n;i++)
    cout << arr[i] << " ";



}

