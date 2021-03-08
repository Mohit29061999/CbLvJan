#include <iostream>
using namespace std;

int power(int x,int y){  // do multiplication of x y times
    //base case:
    if(y==0)
        return 1;

    //call the simple problem
    int ans =power(x,y-1);  // do multiplication of x y-1 times
    return ans*x;
}






int main(){
   cout << power(2,3);
}





