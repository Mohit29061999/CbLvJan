#include <iostream>
using namespace std;


int main(){
    int *a=new int; //create a variable of int type using dma
    *a=10;
    cout << *a << endl;


    int *arr=new int[10]; //create an array of size 10
    for(int i=0;i<10;i++){
       // *(arr+i)=i+1;
        arr[i]=i+1;
    }


    for(int i=0;i<10;i++){
       // cout << *(arr+i) << " ";
        cout << arr[i] << " ";
    }

    delete a; //delete memory from heap
    a=NULL;

    delete []arr; ///deleting an array
    arr=NULL;


}
