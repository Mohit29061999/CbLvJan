#include <iostream>
using namespace std;

///way 1: recursion + memo
int dp[100];  ///n<100

int fibo(int n){

    if(n==0 || n==1){
        return n;
    }

    ///check if it has been already solved or not
    if(dp[n]!=-1)
        return dp[n];

    dp[n]=fibo(n-1)+fibo(n-2);
    return dp[n];
}

int main(){

    for(int i=0;i<100;i++)
        dp[i]=-1;
    int n;
    cin>>n;
    cout << fibo(n) << endl;

    ///for second way: bottom up
    int dp1[n+1];
    dp1[0]=0;
    dp1[1]=1;
    for(int i=2;i<=n;i++)
        dp1[i]=dp1[i-1]+dp1[i-2];

    cout << dp[n] << endl;



}
