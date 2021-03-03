#include <iostream>
using namespace std;



int main(){



  int a[][4]={1,2,3,4,5,6,7,8,9,10,11,12};

  int r_s=0;
  int c_s=0;
  int r_e=2;   //n-1
  int c_e=3;  //m-1

  while(r_s<=r_e && c_s<=c_e){
        //no rows left or no columns left
        //print first row first
        for(int i=c_s;i<=c_e;i++)
        cout << a[r_s][i] << " ";

         r_s++;  //since starting row is printed

         //print last col
         for(int i=r_s;i<=r_e;i++)
            cout << a[i][c_e]<< " ";
         c_e--;  //since we have printed last col

         //print last row and col in reverse order
        if(r_s<=r_e){
              for(int i=c_e;i>=c_s;i--)
        cout << a[r_e][i] << " ";
        r_e--;
        }

         //print first col with rows in reverse order
         if(c_s<=c_e){
              for(int i=r_e;i>=r_s;i--)
            cout << a[i][c_s]<< " ";
            c_s++;  //printed first col so no need for this col again
         }

  }



}





