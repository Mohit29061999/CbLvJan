//problem link: https://leetcode.com/problems/rotting-oranges/

class fruit{
    public:
    int x;
    int y;
    int t;

    fruit(int a,int b,int c){
        x=a;
        y=b;
        t=c;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<fruit>q;
        int ans =0;

        ///insert all orange that were rotten initially
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    fruit f(i,j,0);
                    q.push(f);
                }
            }
        }

        while(!q.empty()){
            fruit f=q.front();
            q.pop();
             int x=f.x;
            int y=f.y;
            int t=f.t;
           // ans = max(ans,t);
            ans =t;
            ///make it's adjacent fresh orange rotten
            //down direction
            if(x+1<n && grid[x+1][y]==1){
                grid[x+1][y]=2;
                fruit f1(x+1,y,t+1);
                q.push(f1);
            }

            //up direction
            if(x-1>=0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                fruit f1(x-1,y,t+1);
                q.push(f1);
            }


             //left direction
            if(y-1>=0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                fruit f1(x,y-1,t+1);
                q.push(f1);
            }

              //right direction
            if(y+1<m && grid[x][y+1]==1){
                grid[x][y+1]=2;
                fruit f1(x,y+1,t+1);
                q.push(f1);
            }


        }

        ///whether there is a fresh orange left or not
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }

        return ans;
    }
};
