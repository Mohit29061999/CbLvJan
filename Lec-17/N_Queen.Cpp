#include <iostream>
using namespace std;

//it will tell whether you can place queen at r,c cell or not
//true means yes false means not
bool isSafe(int sol[][4],int r,int c,int n){  //r is row and c is col number of this cell
 //check for current row
 for(int i=0;i<c;i++){
    if(sol[r][i]==1)
        return false;
 }

 ///upper diagonal now for which row-- and col--
 int c_r=r-1;
 int c_c=c-1;
 while(c_r>=0 && c_c>=0){
    if(sol[c_r][c_c]==1)
        return false;
    c_r--;
    c_c--;
 }

  ///lower diagonal now for which row++ and col--
 c_r=r+1;
  c_c=c-1;
 while(c_r<n && c_c>=0){
    if(sol[c_r][c_c]==1)
        return false;
    c_r++;
    c_c--;
 }

 return true;

}

bool placeQueen(int sol[][4],int c,int n){
    //base case
    if(c==n){
         //print the sol
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    //i am fooling the recursion so that it finds the other sol
    return false;
    }

    //try placing queen in all the rows of current col
    for(int r=0;r<n;r++){
        //ask whether i can place queen here or not
        if(isSafe(sol,r,c,n)){
            //place the queen here
            sol[r][c]=1;
            //tell recursion place rest of the queens
            bool ans = placeQueen(sol,c+1,n);
            if(ans==true){
                return true;
            }
           //revert back my changes
           sol[r][c]=0;
        }
    }

    return false;
}



int main(){
 int sol[4][4]={0};
 placeQueen(sol,0,4);
/*if(placeQueen(sol,0,4)==false){

    cout << "No Solution" << endl;
} */
}

