#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

	int cur=0; //current
	int next=1; //your next number

	//print n rows
	for(int row=1;row<=n;row++){
		//in rowth row print row number
		for(int count =1;count<=row;count++){
			//print current number
			cout << cur << " ";
			//genrate next number
			int sum =cur+next;
			//move next one step ahead and cur one step ahead
		//	int temp = next;
		cur = next;
			next=sum;



		}

		//print new row on a new line
		cout << endl;
	}





}

