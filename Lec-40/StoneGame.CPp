///problem link: https://leetcode.com/problems/stone-game/


int dp[501][501];

int solve(vector<int>&v,int i,int j){
    ///base case:if only one pile of stone is left
    if(i==j)
        return v[i];

    ///base case 2: if two pile of stone is left
    if(i+1==j){
        return max(v[i],v[j]);
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    ///first case: take the first pile of stone
    int val = v[i];

    ///opponent can take first or last pile
    int x=solve(v,i+2,j);  ///opponent is taking first pile too
    int y=solve(v,i+1,j-1);  ///opponent is taking last pile
    int first = val + min(x,y);

    ///when we are selecting last pile of stone
    val = v[j];


    ///opponent can take first or last pile
     x=solve(v,i+1,j-1);  ///opponent is taking first pile too
     y=solve(v,i,j-2);  ///opponent is taking last pile
    int last = val + min(x,y);

    dp[i][j]=max(first,last);
    return dp[i][j];


}
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
     for(int i=0;i<=500;i++){
         for(int j=0;j<=500;j++)
             dp[i][j]=-1;
     }
        int n=piles.size();
        int x=solve(piles,0,n-1);  ///x is maximum value that we get
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=piles[i];

        if(x>=sum-x)
            return true;
        else
            return false;



    }
};
