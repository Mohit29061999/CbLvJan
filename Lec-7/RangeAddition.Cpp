#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        a[i]=0;

    int k;
    cin>>k; //k is no of operations

    for(int i=1;i<=k;i++){
        int s,e,val;
        cin>>s>>e>>val;

        //increase e by val and decrease s-1 by val
        a[e]+=val;
        if(s!=0)
            a[s-1]-=val;
    }

    //do arr[i]+=a[i+1] for every index from n-2 to 0
    for(int i=n-2;i>=0;i--)
        a[i]+=a[i+1];

    for(int i=0;i<n;i++)
        cout << a[i] << " ";


}


