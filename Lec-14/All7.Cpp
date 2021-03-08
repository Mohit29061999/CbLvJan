#include <iostream>
using namespace std;

void printAll(int arr[],int index){
    //base case:when all elements are searched
    if(index<0)
        return;


    //print all 7 from 0 to index-1
    printAll(arr,index-1);

     //check if index has value 7 or not
    if(arr[index]==7){
        cout << index+1 << " ";
    }
}

void printLast(int arr[],int index){
    //base case:when all elements are searched
    if(index<0)
        return;

         //check if index has value 7 or not
    if(arr[index]==7){
        cout << index+1 << " ";
        return;
    }

    //print all 7 from 0 to index-1
    printLast(arr,index-1);


}

void printFirst(int arr[],int index,bool &found){
    //base case:when all elements are searched
    if(index<0)
        return;



    //print all 7 from 0 to index-1
    printFirst(arr,index-1,found);

         //check if index has value 7 or not
    if(found ==false && arr[index]==7){
        cout << index+1 << " ";
        found =true;
       // return;
    }


}


int main(){
   int arr[]={7,1,7,7,2};
   int n=5;
   bool found =false;
   //printAll(arr,n-1);
   printFirst(arr,n-1,found);

}


