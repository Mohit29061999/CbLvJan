///problem link: https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();

        int move[n*n+1]; ///1-based indexing

        int index=1;

        int turn =0; ///turn =0 means go in increasing col order
        for(int i=n-1;i>=0;i--){
            if(turn==0){
                //go in increasing col order
                for(int j=0;j<n;j++){
                    move[index]=board[i][j];
                    index++;
                    turn =1;
                }
            }else{
                //go in deccreasing col order
                for(int j=n-1;j>=0;j--){
                    move[index]=board[i][j];
                    index++;
                    turn =0;
                }
            }

        }

    /*    for(int i=1;i<=n*n;i++)
            cout << move[i] << " ";
        cout << endl; */
        int ans =0;
        bool visited[n*n+1];
        for(int i=1;i<=n*n;i++)
            visited[i]=false;
        queue<pair<int,int>>q;
        q.push({1,0});
        visited[1]=true;

        while(!q.empty()){
              pair<int,int>p =q.front();  ///remove the first node from queue
              q.pop();
              int x=p.first;
              int t=p.second;  ///t is no of dice throw to reach x position

              if(x==n*n){
                  return t;
              }

              for(int i=1;i<=6;i++){  ///value of current dice throw
                   int y=x+i;
                    if(y>n*n){
                        continue;
                        ///break;
                    }
                   if(move[y]!=-1){
                       y=move[y];  ///for snake or ladder, you won't stop at y
                                   ///you have to follow ladder/snake
                   }

                  if(!visited[y]){
                      q.push({y,t+1});
                      visited[y]=true;
                  }

              }

        }

        return -1;



    }
};
