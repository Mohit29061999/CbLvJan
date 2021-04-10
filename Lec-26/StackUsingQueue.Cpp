#include <iostream>
#include <queue>
using namespace std;

class Stack{
private:
    queue<int>q1;
    queue<int>q2;
    int cs;  ///q1 && q2 combined ka size

public:
    Stack(){
       cs=0;
    }

    //insert it like a queue and manage it while poping
    void push(int val){
        cs++;
        if(q1.empty() && q2.empty()){
            q1.push(val);
            return;

        }

        else if(!q1.empty()){
            q1.push(val);
        }
        else
            q2.push(val);
    }

    void pop(){
        cs--;
        //access the last element
        if(!q1.empty()){
            ///remove all the elements from q1 and push them to q2
            /// except the last one
            while(q1.size()>1){
                int x=q1.front();
                q1.pop();
                q2.push(x);
            }

            ///remove the last element
            q1.pop();


        }
        else{
            ///q2 is non-empty and q1 is empty
            ///remove all the elements from q2 and push them to q1
            /// except the last one
            while(q2.size()>1){
                int x=q2.front();
                q2.pop();
                q1.push(x);
            }

            ///remove the last element
            q2.pop();
        }
    }

    int top(){

         if(q1.empty()  && q2.empty()){
                cout << "stack is empty";
            return -1;
         }
        if(!q1.empty()){
            ///remove all the elements from q1 and push them to q2
            /// except the last one
            while(q1.size()>1){
                int x=q1.front();
                q1.pop();
                q2.push(x);
            }


            int x=q1.front();
            q1.pop();
            q2.push(x);
            return x;

        }
        else{
            ///q2 is non-empty and q1 is empty
            ///remove all the elements from q2 and push them to q1
            /// except the last one
            while(q2.size()>1){
                int x=q2.front();
                q2.pop();
                q1.push(x);
            }


            int x=q2.front();
            q2.pop();
            q1.push(x);
            return x;
        }
    }

    bool empty(){
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }

    int size(){
        return cs;
    }

};


int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  while(!s.empty()){
    int x=s.top();
    cout << x << " ";
    s.pop();
  }


}


