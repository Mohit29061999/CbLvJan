#include <iostream>
using namespace std;


int main(){
    int n,d;
    cin>>n>>d;

    float ans =0;
    float inc =1;

    //to get d digits
    for(int i=1;i<=d+1;i++){

        while(ans*ans<=n){  //ans =3.8*3.8<=15  //ans+=inc;
            ans+=inc;  //ans = ans+inc;
        }
        ans=ans-inc;
        //update inc
        inc = inc/10;
    }
  // cout << i << endl;
    //ans = 4+=0.0 = 4+=0.00
    cout << ans << endl;
}


