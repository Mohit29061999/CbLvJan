#include <iostream>
using namespace std;



int main(){


   /*char arr[][4]={"abc","efg","ghi","edf"};
              //always specify col
              for(int i=0;i<4;i++)
                cout << arr[i] << endl; */


  //int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //giving col is mandatory
  int arr[][3]={1,2,3,4,5,6,7,8,9};
// int arr[3][3];  //defining the size is mandatory if we are giving elements later one
 /* for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
        cin>>arr[i][j];
  } */
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
        cout << arr[i][j] << " ";
  }

}


