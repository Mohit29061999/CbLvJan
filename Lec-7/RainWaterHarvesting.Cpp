#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;  //how many elevations are there?

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];   //height of every elevations

    int l[n],r[n];   //l[i]: max of 0 to ith index  r[i]: max of ith to n-1th index

    //write l;
    l[0]=a[0];
    for(int i=1;i<n;i++){
        //l[i]:max of 0 to ith index = max( max of 0 to i-1,current_h)=max(l[i-1],a[i]);
        if(l[i-1]>a[i]){
            l[i]=l[i-1];
        }
        else{
            l[i]=a[i];
        }
    }
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
          //r[i]:max of ith to n-1 index = max( max of i+1 th  to n-1 th index,current_h)=max(r[i+1],a[i]);
        if(r[i+1]>a[i]){
            r[i]=r[i+1];
        }
        else{
            r[i]=a[i];
        }
    }

    int ans =0;
    for(int i=0;i<n;i++){
        //go to each bar ,add water stored on that bar
        //find min of l[i] and r[i]
        //water stored on every bar = min(l[i],r[i])-current_h
        int z;  //min of l[i] and r[i]
        if(l[i]<r[i]){
            z=l[i];
        }
        else
            z=r[i];
        ans +=(z-a[i]);

    }

    cout << ans << endl;


}
