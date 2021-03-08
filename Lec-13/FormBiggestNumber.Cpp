//problem link : https://hack.codingblocks.com/app/contests/2115/1086/problem

#include<iostream>
#include <algorithm>
using namespace std;

bool compare(string x,string y){ //x is at lower index and y is at greater index
	string x_y=x+y;
	string y_x=y+x;

	//true means no change in order and false means change in order
	return x_y>y_x;
}

int main() {
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n;
		cin>>n;
		string arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];

		//sort(arr,arr+n); //sorting in increasing order
         sort(arr,arr+n,compare);
		for(int i=0;i<n;i++)
		cout << arr[i] ;
		cout << endl;
	}
}