#include <iostream>
using namespace std;

//it will give the co-ordinate of an empty cell
bool emptyCell(int sudo[][9],int &r,int &c){
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(sudo[i][j]==0){
            r=i;
            c=j;
            return true;
        }
    }
}
return false;

}

//telling you whether you can place a particular value in a cell or not
bool canPlace(int sudo[][9],int r,int c,int val){
    //checking whether this value has occurred in this row or not and this col
    for(int i=0;i<9;i++){
        if(sudo[r][i]==val)
            return false;
        if(sudo[i][c]==val)
            return false;
    }

    //check for 3*3 grid
    //starting point of 3*3 grid for current cell
    int r_s=r-r%3;
    int c_s=c-c%3;
    for(int i=r_s;i<r_s+3;i++){
        for(int j=c_s;j<c_s+3;j++){
            if(sudo[i][j]==val)
                return false;
        }
    }
    return true;

}


bool solveSudo(int sudo[][9]){
    //find one empty cell
    int r=-1;
    int c=-1;
    //base case:already filled all the cell
    emptyCell(sudo,r,c);
    if(r==-1 && c==-1)
        return true;

    //r and c will be telling me location of  one empty cell
    //fill it
    //try all values in this empty cell
    for(int i=1;i<=9;i++){
        if(canPlace(sudo,r,c,i)){
            //fill this cell with value i;
            sudo[r][c]=i;
                //recursion will fill rest of the cell
           bool ans= solveSudo(sudo);
           if(ans ==true){
               return true;
           }

           //for false:try different value
           sudo[r][c]=0;


        }
    }

    return false;





}



int main(){
  int grid[][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

  solveSudo(grid);

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
        cout << grid[i][j] << " ";
    cout << endl;
  }
}


