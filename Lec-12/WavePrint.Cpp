#include <iostream>
using namespace std;



int main(){



  int arr[][3]={1,2,3,4,5,6,7,8,9};

  for(int col=0;col<3;col++){
        if(col%2==0){
                //else print from first row
    for(int row=0;row<3;row++)
        cout << arr[row][col] << " ";
        }
        else{
                //for odd col,print from last row
              for(int row=2;row>=0;row--)
        cout << arr[row][col] << " ";
        }
        }


}



