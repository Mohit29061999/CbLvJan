///problem link:https://codeforces.com/problemset/problem/1529/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define int long long  ///make int to long long

void solve(){

  int n;
  cin>>n;

  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];

    sort(a,a+n);

    int min_pos=INT_MAX;
    int min_abs_diff =INT_MAX;
    int neg=0;
    ///count of neg no including 0 too
    for(int i=0;i<n;i++){
        if(a[i]<=0)
        neg++;
    }

    if(neg==0){
        cout << 1 << endl;
        return;
    }

    if(neg==n){
        cout << n << endl;
        return ;
    }

    ///find difference between adjacent -ve no
    for(int i=1;i<n;i++){
        if(a[i]<=0){
            min_abs_diff= min(min_abs_diff,abs(a[i]-a[i-1]));

        }
        else{
            min_pos = min(min_pos,a[i]);
        }
    }

   if(min_pos<=min_abs_diff){
       ///we can include the +ve value
       cout << neg +1 << endl;
   }
  else
  cout << neg << endl;





}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     ///to make input output fast



    int t;
    cin>>t;



while(t--){
    solve();
}






}
