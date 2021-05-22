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

        void dijkstra(int s,int dest){

        /*    for(int i=0;i<n;i++){
                for(int j=0;j<v[i].size();j++){
                      if(v[i][j].first>i){
                          cout << i << " " << v[i][j].first << " " << v[i][j].second<< endl;
                      }
                }
            } */

            set<pair<int,int>>s1;  ///p.first means distance of that node
                                  ///p.second means the value of node

            int par[n],dist[n];

            for(int i=0;i<n;i++){
                par[i]=-1;  ///i haven't reached ith node
                dist[i]=INT_MAX;
            }

            s1.insert({0,s});
            dist[s]=0;
            par[s]=-1;

            while(!s1.empty()){
                 ///take out the node with min dist
                 pair<int,int>p = *(s1.begin());
                 int x=p.second;
                 s1.erase({p.first,p.second}); ///remove the begin element from set

                 ///if x==dest,i have got the min dist
                 if(x==dest)
                 break;

                 ///see if i can go to some other vertex at min cost using x
                 for(int i=0;i<v[x].size();i++){
                      int y=v[x][i].first;
                      int wt=v[x][i].second;

                      if(dist[y]>dist[x]+wt){
                        ///go to y from x
                        ///see if y is in set or not
                        if(s1.find({dist[y],y})!=s1.end()){
                            s1.erase({dist[y],y});  ///remove the previous entry
                        }

                        dist[y]=dist[x]+wt;
                        s1.insert({dist[y],y});
                        par[y]=x;
                      }
                 }


            }

            cout << dist[dest] << endl;

            ///print the path
            int i=dest;
            while(par[i]!=-1){ ///as long as we are not at the source vertex
                 //   cout << v[par[i]][i].second << endl;
                   cout << i << " " << par[i] << " " << dist[i] - dist[par[i]]<< endl;
                    i=par[i];
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
   int s=0;
   int dest = 5;
    g.dijkstra(s,dest);
}







