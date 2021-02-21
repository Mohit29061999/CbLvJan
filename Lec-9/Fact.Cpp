#include <iostream>
using namespace std;

int fact(int n){
    int ans =1;
    for(int i=1;i<=n;i++)
        ans=ans*i;
    return ans;
}

int nCr(int n,int r){
    int f1=fact(n);  //n!
    int f2=fact(n-r);  //n-r!
    int f3=fact(r);     //r!
    int ans = f1/(f3*f2);
    return ans;
}

int main(){
    int n;
    cin>>n;

   // cout << fact(n) << endl;
    cout << nCr(5,2) << endl;
    cout << "Hello World";


}


