//problem link: https://www.spoj.com/problems/MIXTURES/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int sum[101][101] ;  ///sum from i to j

int solve(int a[],int i,int j){
    //base case:for one bottle
    if(i==j)
    return 0;

    //base case: for two bottle
    if(i+1==j){
        return a[i]*a[i+1];
    }

    if(dp[i][j]!=-1)
    return dp[i][j];

    ///try every case for the last mixing by taking all left and right part
    int ans =INT_MAX;

    for(int k=i;k<j;k++){  ///k is representing last bottle of left part
         ///find cost of mixing
         int l=solve(a,i,k);
         int r=solve(a,k+1,j);
         ///mix left part and right part now
         int smoke = sum[i][k]* sum[k+1][j];
         ans =min(ans,l+r+smoke);
    }

    dp[i][j]=ans;
    return dp[i][j];


}

int main() {
     int n;
     while(cin>>n){
         int a[n];
         for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<=100;i++){
          for(int j=0;j<=100;j++){
          dp[i][j]=-1;
          sum[i][j]=-1;
          }

      }
      for(int i=0;i<n;i++)
      sum[i][i]=a[i];

      for(int l=2;l<=n;l++){
          for(int s=0;s<=n-l;s++){
              int e=s+l-1;
              sum[s][e]=(a[s]+sum[s+1][e])%100;
          }
      }

      cout << solve(a,0,n-1) << endl;


     }
}

