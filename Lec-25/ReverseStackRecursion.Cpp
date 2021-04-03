#include <iostream>
#include <stack>
using namespace std;

void insertAtbottom(stack<int>&s,int val){
    //base case: no element before so new element will be default be at bottom
    if(s.empty()){
        s.push(val);
        return;
    }
    int x=s.top();
    s.pop();
    insertAtbottom(s,val);
    s.push(x);
}

void reverse(stack<int>&s){
    //base case: no element before so new element will be default be at bottom
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    reverse(s); //reverse everything without top element
    insertAtbottom(s,x);

}




int main(){

   stack<int>s;
   s.push(4);
   s.push(3);
    s.push(2);
   s.push(1);

   reverse(s);

   while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
   }




}




