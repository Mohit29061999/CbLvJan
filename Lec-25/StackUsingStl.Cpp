#include <iostream>
#include <stack>
using namespace std;





int main(){

    stack<int> s;
    int n;
    cin>>n;
    while(n){
            int x;
    cin>>x;
    s.push(x);
    n--;
    }

   // cout << v[v.size()-1] << endl;

      while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
      }

      cout << s.size() << endl;





}


