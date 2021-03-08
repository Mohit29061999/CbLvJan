//problem link: https://hack.codingblocks.com/app/contests/2115/446/problem


#include<iostream>
using namespace std;



int main() {
	int k;
	cin>>k;

	string s;
	cin>>s;
    int n=s.length();
	int ans =0;
	//try all a ie. k b
	int c=0;  //count of b
	int st=0;
	for(int i=0;i<n;i++){ //try all index as ending point of your substring
       //check if current character is b
	   if(s[i]=='b'){
		   while(c==k){ //if i already have k b then can't include it
                //move starting point
				if(s[st]=='b')
				c--;
				st++;
		   }
		   
		   c++;  //adding current b
	   }
	   ans = max(ans,i-st+1);
	}

		//try all b ie. k a
	 c=0;  //count of a
	 st=0;
	for(int i=0;i<n;i++){ //try all index as ending point of your substring
       //check if current character is b
	   if(s[i]=='a'){
		   while(c==k){ //if i already have k b then can't include it
                //move starting point
				if(s[st]=='a')
				c--;
				st++;
		   }
		   
		   c++;  //adding current b
	   }
	   ans = max(ans,i-st+1);
	}
    cout << ans << endl;
	return 0;
}