//problem link: https://hack.codingblocks.com/app/contests/2115/492/problem


#include<iostream>
#include <stack>
using namespace std;


int main() {
       int t;
	   cin>>t;

	   while(t){
		   t--;
		   string s;
		   cin>>s;
           bool ans = true;  ///ans is telling whether there is duplicate brackets or not
		                    /// true means no duplicate brackets else there is
		   stack<char>s1;
		   int n=s.length();
		   for(int i=0;i<n;i++){
			   if(s[i]=='('){
				   s1.push(s[i]);
			   }

			   else if(s[i]==')'){
				    int c=0;  ///c is telling number of characters in between the bracktes
			       while(!s1.empty() && s1.top()!='('){
					   c++;
					   s1.pop();
				   }
				   s1.pop();
				   if(c==0)
				   ans = false;
			   }

			   else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
			   s1.push(s[i]);

			   else
                ///ignore
		   }

		   if(ans == false){
			   cout << "Duplicate Found " << endl;
		   }
		   else{
                cout <<   "No Duplicates Found " << endl;
		   }
	   }
}
