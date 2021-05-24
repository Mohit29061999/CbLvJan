#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<vector<pair<int,int>>>v; ///to store the graph p.first means vertex connected
                                      ///p.second  to store the weight with that edge
    int n;  ///number of vertex in the graph
    public:
        Graph(int v1){
            n=v1;

            ///create an empty graph
            for(int i=0;i<n;i++){
                vector<pair<int,int>> temp;
                v.push_back(temp);
            }
        };

        void addEdge(int x,int y,int z,bool bidir = true){
            v[x].push_back({y,z});
            if(bidir){
                v[y].push_back({x,z});
            }

        }

        void prim(){

           bool visited[n];  ///vertex that are finalised in mst
           int par[n],dist[n];
           for(int i=0;i<n;i++){
              visited[i]=false;
              par[i]=-1;
              dist[i]=0;
           }

           set<pair<int,int>>s;
           visited[0]=true;
           par[0]=-1;
           dist[0]=0;


           s.insert({0,0});

          /// int sum=0;  ///cost of mst(sum of edges)

           while(!s.empty()){
                    ///take out the vertex with min weight
                    pair<int,int> p = *(s.begin());  ///iterator
                    int x=p.second;
                    visited[x]=true;
                    s.erase(s.begin());  ///remove the current vertex from set
                   // sum+=p.first;

                    ///go to all the adjacent vertex of this vertex
                    for(int i=0;i<v[x].size();i++){
                        int y=v[x][i].first;
                        int wt=v[x][i].second;
                        if(visited[y]==false){
                              ///see if using this edge i can reach y with less weight
                              if(dist[y]>wt){
                                ///if it is already in set
                                if(s.find({dist[y],y})!=s.end()){
                                    s.erase({dist[y],y});  ///removing the previous entry
                                }

                                dist[y]=wt;
                                s.insert({dist[y],y});
                                par[y]=x;
                              }
                        }
                    }

           }

           int sum=0;
           for(int i=0;i<n;i++)
            sum+=dist[i];

           cout << sum << endl;


           ///print mst
           for(int i=1;i<n;i++){
            cout << i << " " << par[i] << " " << dist[i] << endl;
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
        int x,y,z;
        cin>>x>>y>>z;
        g.addEdge(x,y,z);
    }

    g.prim();
}








