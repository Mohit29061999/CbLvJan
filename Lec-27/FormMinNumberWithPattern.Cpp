#include<iostream>
#include <stack>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;

		stack<int>s1;
		int n=s.length();

		for(int i=0;i<=n;i++){
			s1.push(i+1);  ///by default D pattern is followed

			///if it is I or end then empty the stack
			if(i==n || s[i]=='I'){
				///empty the stack
				while(!s1.empty()){
					cout << s1.top();
					s1.pop();
				}
			}
		}
		cout << endl;
	}
	return 0;
}
