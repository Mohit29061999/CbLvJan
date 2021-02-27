#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	cout << 1 << endl;
	//loop for n-1 rows
	for(int i=1;i<=n-1;i++){
		//for every row,print i+1 numbers
		for(int j=1;j<=i+1;j++){
			//check if it is first or last
			if(j==1 || j==i+1)
			cout << i;
			else
			cout << 0;
		}
		cout << endl;
	}

	return 0;
}
