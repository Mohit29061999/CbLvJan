#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;

    //check for each number from 2 to n whether they are prime/not
    for(int i=2;i<=n;i++){
            //inorder to i to be prime,it should not be divisible by any value
            //from 2 to i-1
        int j=2;
         while(j<=i-1){
            if(i%j==0){
            //this means i is not prime
                break;
            }
            j++;
         }

         //if i==j then i is prime else not
         if(i==j){
            cout << i << endl;
         }
    }



}









