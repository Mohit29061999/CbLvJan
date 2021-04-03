#include <iostream>
#include <stack>
using namespace std;


bool isValid(string &s){
    stack<char>s1;
    int n=s.length();

    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            s1.push(s[i]);
        else if(s[i]==')'){
            if(s1.empty() || s1.top()!='('){

                return false;
            }
            s1.pop();
        }

         else if(s[i]=='}'){
            if(s1.empty() || s1.top()!='{'){

                return false;
            }
            s1.pop();
        }

         else if(s[i]==']'){
            if(s1.empty() || s1.top()!='['){

                return false;
            }
            s1.pop();
        }
    }

   if(s1.empty())
    return true;
   else
    return false;
}




int main(){

    string s;
    cin>>s;

    if(isValid(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;




}



