///problem link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];

        dp[0][0]=grid[0][0];
        ///fill the first row
        for(int i=1;i<m;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];

        //fill the first col
        for(int i=1;i<n;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];

        ///fill rest of the table
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }

        int i=n-1;
        int j=m-1;

        while(i>=0 && j>=0){
            cout << grid[i][j] << " ";
            if(i-1>=0 && j-1>=0){
                if(dp[i-1][j]<dp[i][j-1]){
                    i--;
                }
                else
                    j--;
            }
            else{
                if(i-1>=0)
                    i--;
                else
                    j--;
            }


        }
        return dp[n-1][m-1];

    }
};
