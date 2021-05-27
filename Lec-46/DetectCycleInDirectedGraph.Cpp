
///problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

bool dfs(vector<int>adj[],int i,bool visited[],bool callStack[]){
    visited[i]=true;
    callStack[i]=true;  ///dfs for ith vertex is started
    
    for(int j=0;j<adj[i].size();j++){
        int y=adj[i][j];
        
        if(!visited[y]){
            ///call dfs for y
            bool c=dfs(adj,y,visited,callStack);
            if(c==true)
            return true;
        }
        else{
            ///y is already visited
            ///if a adjacent node is already visited and is in the call 
            ///stack then there is a cycle
            if(callStack[y]==true)
            return true;
        }
    }
    
    callStack[i]=false;
    return false;
}

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	bool visited[V];
	   	bool callStack[V];
	   	
	   	for(int i=0;i<V;i++){
	   	    visited[i]=false;
	   	    callStack[i]=false;
	   	}
	   	
	   	for(int i=0;i<V;i++){
	   	    if(visited[i]==false){
	   	        bool c=dfs(adj,i,visited,callStack);
	   	        if(c==true)
	   	        return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends