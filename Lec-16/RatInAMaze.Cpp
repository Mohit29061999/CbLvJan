#include <iostream>
using namespace std;

bool ratInAMaze(char arr[][5],int sol[][4],int i,int j,int n,int m){
    //base case
    if(i==n-1 && j==m-1){
        if(arr[i][j]=='X')  //whether last cell is blocked
            return false;
        sol[i][j]=1;
return true;
    }
    sol[i][j]=1; //make this cell as a part of your solution
    //try the right cell
    if(j+1<m && arr[i][j+1]!='X'){
        bool kya_right_se_rasta_h=ratInAMaze(arr,sol,i,j+1,n,m);
        if(kya_right_se_rasta_h)
            return true;

    }

    //try the down cell
    if(i+1<n && arr[i+1][j]!='X'){
        bool kya_down_se_rasta_h=ratInAMaze(arr,sol,i+1,j,n,m);
        if( kya_down_se_rasta_h)
            return true;

    }

    sol[i][j]=0; ///this cell is not a part of solution ie.backtrack
    return false;



}



int main(){
char arr[4][5]={"OXOO","OOXO","OXOO","OOOO"};
int sol[4][4];
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        sol[i][j]=0;
}

if(ratInAMaze(arr,sol,0,0,4,4)){
    for(int k=0;k<4;k++){
    for(int w=0;w<4;w++)
        cout << sol[k][w] << " ";
    cout << endl;
    }
}
else
    cout << "NO SOl" << endl;

}





