///problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool dfs(vector<int>adj[],int i,int par,bool visited[]){
     visited[i]=true; 
     
     ///go to all adjacent vertex
     for(int j=0;j<adj[i].size();j++){
         int y=adj[i][j];
         if(!visited[y]){
             ///call dfs for y
             bool c=dfs(adj,y,i,visited);
             if(c==true)
             return true;
             
         }
         else{
             ///if it is already visited and is not the parent
             if(par!=y)
             return true;
         }
     }
     
     ///ending point of dfs call for i
     return false;  ///no cycle
     
}

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    visited[i]=false;
	    
	    ///call dfs from every connected component
	    for(int i=0;i<V;i++){
	        if(visited[i]==false){
	            bool c=dfs(adj,i,-1,visited);
	            if(c==true)
	            return true;
	        }
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends