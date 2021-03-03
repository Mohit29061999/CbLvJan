#include <iostream>
using namespace std;



int main(){



  int arr[][3]={1,2,3,4,5,6,7,8,9};
   int target;
   cin>>target;
   bool found =false;  //false means not found ,else it is found
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==target){
                found =true;
                cout << i+1 << " "<< j+1 << endl;  //to get 1 based indexing
                break;
            }
        }
    }

    if(found==false)
    cout << -1 << endl;

}




