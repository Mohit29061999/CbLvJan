///problem code: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int dp[1001][1001];

int solve(int w,int n,int wt[],int val[]){
    if(w==0 || n==0){
        dp[w][n]=0;
    return 0;
    }

    if(dp[w][n]!=-1)
    return dp[w][n];
    ///take nth item
    int ans1=0;
    if(wt[n-1]<=w){
        ans1=solve(w-wt[n-1],n-1,wt,val)+val[n-1];
    }
    ///not taking the nth item
    int ans2=0;
    ans2=solve(w,n-1,wt,val);
    dp[w][n]  = max(ans1,ans2);
    return dp[w][n];

}

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {   for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++)
        dp[i][j]=-1;
    }

    return solve(W,n,wt,val);

    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
	return 0;
}  // } Driver Code Ends
