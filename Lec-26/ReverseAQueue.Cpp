#include <iostream>
#include <queue>
using namespace std;

void reverse(queue<int> &q){
    //base case
    if(q.size()==0)
        return;

    //store front value
    int x=q.front();
    q.pop();

    //reverse everything except the front node
    reverse(q);

    q.push(x);
}


int main(){
queue<int>q;

q.push(1);
q.push(2);
q.push(3);
q.push(4);

reverse(q);

while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}

}

