//problem link: https://www.spoj.com/problems/PT07X/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&v,int i,int par,int dp[][2]){
    dp[i][0]=1; ///including ith node
    dp[i][1]=0;  ///not including ith node
    
    for(int j=0;j<v[i].size();j++){
        ///call dfs only if it is not par
        int y=v[i][j];
        if(par!=y){
            dfs(v,y,i,dp);
            dp[i][0]+=min(dp[y][0],dp[y][1]);  ///we have included the ith node
                                               ///so we have a choice to keep the y or not
            dp[i][1]+=dp[y][0];               ///we don't have a choice as i is not included
        }
        
    }
    
    
}

int main() {
	int n;
	cin>>n;
	
	///create an empty graph
	vector<vector<int>>v;
	for(int i=0;i<n;i++){
	    vector<int>temp;
	    v.push_back(temp);
	}
	
	for(int i=0;i<n-1;i++){
	    int x,y;
	    cin>>x>>y;
	    x--;
	    y--;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	
	int dp[n][2];
	
	dfs(v,0,-1,dp);
	
	cout << min(dp[0][0],dp[0][1]) << endl;
	
	
}