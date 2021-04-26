#include <iostream>
#include <queue> ///or #include <bits/stdc++.h>
using namespace std;









int main(){
    ///first way with O(n) extra space uses max heap
    int n;
    cin>>n;
    int arr[n];
   // priority_queue<int>pq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
      ///  pq.push(arr[i]);
    }
    int k;
    cin>>k;
   /* int c=0;
    while(c<k){
            c++;
            cout << pq.top() << endl;
        pq.pop();
    } */

    ///second way
    priority_queue<int,vector<int>,greater<int>> pq;

    ///insert the first k values in min heap
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    ///for rest of the values we have to decide whether to insert them or not
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

      while(!pq.empty()){
            cout << pq.top() << endl;
        pq.pop();
    }





}

