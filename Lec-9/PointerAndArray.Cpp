#include <iostream>
using namespace std;

void printArray(int *p,int n){
   *(p+1)=*(p+1)+1;
  // p[1]=p[1]+1;
   for(int i=0;i<n;i++){
        cout << *(p+i) << " ";
    }
   // p++;
    //p[0]++;
}

int main(){
  int a[4]={1,2,3,4};
  printArray(a,4);
  //cout << a[0] << endl;
 // int *p =&(a[0]);  //a[0] means variable at 0th index
 //int *p =a;
 // cout << *p << endl;


}








