#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];

    int x=0;
	for(int i=0;i<n;i++)
	x=x^a[i];

	//finding any set of a^b
	int set_bit=0;
	for(int i=0;i<32;i++){
		int y=(1<<i);
		if(x&y>0){
         set_bit =y;
		 break;
		}
	}

	//divide number in two set-one with ith bit set and other with unset
	int a1=0;
	int b1=0;
	for(int i=0;i<n;i++){
		//check if ith bit is set
		if(a[i]&set_bit>0){
			a1=(a1^a[i]);
		}
		else{
			b1=(b1^a[i]);
		}
	}

	cout << min(a1,b1) << " "<< max(a1,b1) << endl;

}
