#include <iostream>
using namespace std;

int fact(int n){
    //calling first
   // int ans =fact(n-1)*n;

    //base case
    if(n==0 )
        return 1;

    //call for simple case ie.n-1
    int ans =fact(n-1);
    return ans*n;
}

int main(){
    int n;
    cin>>n;
    //cout << fact(0) << endl;
    cout << fact(n) << endl;
}
