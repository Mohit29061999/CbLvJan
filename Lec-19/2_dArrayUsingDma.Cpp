#include <iostream>
using namespace std;


int main(){
   int r,c;
   cin>>r>>c;

  int** arr= new int*[r];

  for(int i=0;i<r;i++){
    arr[i]=new int[c];
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
        arr[i][j]=1;
  }

 /* for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
        cout << arr[i][j] << " ";
    cout << endl;
  } */


  //deleting a 2-d array using dma
  for(int i=0;i<r;i++)
    delete []arr[i];

  //delete outer table too
  delete []arr;



  arr=NULL;

    for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
        cout << arr[i][j] << " ";
    cout << endl;
  }


}


