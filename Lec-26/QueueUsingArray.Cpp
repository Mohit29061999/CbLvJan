#include <iostream>
using namespace std;

class Queue{
private:
    int *arr;
    int f;
    int e;
    int cs;
    int n;

public:
    Queue(int s){
        n=s;
        cs=0;
        arr = new int[s];
        f=0;
        e=-1;
    }

    void push(int val){
        if(cs==n){
            cout << "already full" << endl;
            return;
        }

        e=(e+1)%n;
        arr[e]=val;
        cs++;
    }

    void pop(){
        if(cs==0){
            cout << "queue is empty" << endl;
            return;
        }

        f=(f+1)%n;
        cs--;
    }

    int size(){
        return cs;
    }

    bool empty(){
        return cs==0;
    }

    int front(){
        return arr[f];
    }

};

int main(){
Queue q(5);
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}
cout << endl;
cout << q.size();
}
