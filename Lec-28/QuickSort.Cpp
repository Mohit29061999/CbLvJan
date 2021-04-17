#include <iostream>
#include <bits/stdc++.h>
#include <random>  //random function to give random value
#include <cstdlib>  ///adds time with randome function
using namespace std;

int partition(int arr[],int n,int s,int e){
    int leftBoundary =s-1;
    int pivot = arr[e];  ///pivot element is to be put at its correct position

    for(int j=s;j<e;j++){
        if(arr[j]<=pivot){
            ///increase your leftboundary by 1
            leftBoundary++;
            ///shift this element to left region
            swap(arr[j],arr[leftBoundary]);
        }
    }

    ///place the last element at its correct position
    swap(arr[leftBoundary+1],arr[e]);
    return leftBoundary+1;  ///give the index of last element
}

int RandomQuickSort(int arr[],int n,int s,int e){
    ///randomly swap the last with any index
    srand(time(0));  ///to get the different random value each time
    int r_e = s+(rand())%(e-s);   ///select a random index as pivot and swap them
    swap(arr[r_e],arr[e]);
    partition(arr,n,s,e);
}

void quickSort(int arr[],int n,int s,int e){
    if(s>=e)
        return;

    int pivot = RandomQuickSort(arr,n,s,e);  ///to get the correct index of the last element

    ///divide the array in two : s to pivot -1 (for less value)
    /// second array will lie from pivot+1 to e(for values greater than last)
    quickSort(arr,n,s,pivot-1);
    quickSort(arr,n,pivot+1,e);

}


int main(){



    int arr[7]={4,1,2,3,6,9,5};
    int n=7;

    quickSort(arr,7,0,6);

    for(int i=0;i<7;i++)
        cout << arr[i] << " ";
}

