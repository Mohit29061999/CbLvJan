///problem link: https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {  ///edge list
          int n=numCourses;
        vector<vector<int>>v;

        ///create an empty graph
        for(int i=0;i<n;i++){
            vector<int>temp;
            v.push_back(temp);
        }

        int indeg[n];
        for(int i=0;i<n;i++)
            indeg[i]=0;

        for(int i=0;i<prerequisites.size();i++){  //travel through the edge list
              int x=prerequisites[i][0];
              int y=prerequisites[i][1];
               v[y].push_back(x);
               indeg[x]++;
        }

        ///find course with 0 indegree
        queue<int>q;
        int c=0;       ///number of courses finished

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
              ///take out the first course in queue and do it
               int x=q.front();
               cout << x << " ";
                q.pop();
               c++;  ///i am doing course x

               for(int i=0;i<v[x].size();i++){
                     int y=v[x][i];
                      indeg[y]--;  ///y was dependend on x and now x is done

                     if(indeg[y]==0){
                         ///we can do y
                         q.push(y);
                     }

               }

        }

        if(c==n){
            return true;   //when graph is non-cyclic
        }

        return false;  ///when graph has cycle


    }
};
