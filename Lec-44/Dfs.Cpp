#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
private:
    vector<vector<int>>v; ///to store the graph
    int n;  ///number of vertex in the graph
    public:
        Graph(int v1){
            n=v1;

            ///create an empty graph
            for(int i=0;i<n;i++){
                vector<int> temp;
                v.push_back(temp);
            }
        };

        void addEdge(int x,int y,bool bidir = true){
            v[x].push_back(y);
            if(bidir){
                v[y].push_back(x);
            }
        }


        ///dfs of a connected component
        void dfs(bool visited[],int i){
            visited[i]=true;
            cout << i << " ";

            ///go to edges coming out from i
            for(int j=0;j<v[i].size();j++){
                  int x=v[i][j];

                  if(visited[x]==false){
                       dfs(visited,x);
                  }
            }
        }

        ///dfs of all components
        void dfsAll(){
            bool visited[n];
            for(int i=0;i<n;i++)
                visited[i]=false;

            for(int i=0;i<n;i++){
                if(visited[i]==false){
                    ///visit it
                    dfs(visited,i);
                }
            }
        }

        void bfs(bool visited[],int s){

            queue<int>q;
            q.push(s);
            visited[s]=true;

            while(!q.empty()){
                int x=q.front();
                q.pop();
                cout << x << " ";

                //try all adjacent vertex of x
                for(int i=0;i<v[x].size();i++){
                    int y=v[x][i];
                    if(visited[y]==false){
                        q.push(y);
                        visited[y]=true;
                    }

                }
            }
        }

        void bfsAll(){
            bool visited[n];
            for(int i=0;i<n;i++)
                visited[i]=false;

            for(int i=0;i<n;i++){
                    if(visited[i]==false)
                          bfs(visited,i);
            }
        }

};



int main(){
    int n;
    cin>>n; //number of vertex in graph

    int e;
    cin>>e;  ///number of edges in graph

    Graph g(n);

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }

    g.bfsAll();
}






