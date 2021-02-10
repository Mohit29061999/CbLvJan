#include <iostream>
using namespace std;


int main(){
    //ask the user what is n
    int n;
    cin>>n;

    int ans =0;   //ans is storing set bits

    while(n>0){

        //check if lsb is set or not
        if(n&1>0){          //any non-zero value is true
           // ans++;      //we get one more set bit
           ans++;
        }

        //right shift n by 1
        n=n>>1;
    }

    cout << ans << endl;
}



