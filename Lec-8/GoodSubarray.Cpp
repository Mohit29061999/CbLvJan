#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int c_sum[n];   //c_sum[i] = sum from 0 to ith index
    c_sum[0]=a[0];
    for(int i=1;i<n;i++){
        c_sum[i]=c_sum[i-1]+a[i];  //sum till 0 to i = sum till 0 to i-1 + a[i] = c_sum[i-1]+a[i]
    }

    //we need remainder only
    for(int i=0;i<n;i++){
        c_sum[i]=c_sum[i]%n;
    }

    int freq[n]={0};
    //freq[0]=1;  //a kind of hack for rem 0
    for(int i=0;i<n;i++){
        freq[c_sum[i]]++;
    }

    int ans =0;
    for(int i=0;i<n;i++){
            int x=freq[i];
            if(i==0){
                ans +=(((x+1)*(x))/2);
            }
            else
        ans +=(((x-1)*(x))/2);
    }
    cout << ans << endl;
    //return 0;

}
