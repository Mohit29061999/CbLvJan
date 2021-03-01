#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n;
		cin>>n;
		int arr[10];
		int i=0;
		while(n){
			int x=n%10;
			arr[i]=x;
			i++;
			n=n/10;
		}
		int mirror[10];
		for(int c=1;c<=i;c++){
			//x is number present at cth index
			int x=arr[c-1];
			//to inverse this store c at xth position
			mirror[x-1]=c;
		}
		bool equal = true;  //true means arr and mirror are equal
		for(int c=0;c<i;c++){
              if(mirror[c]!=arr[c]){
				  equal = false; //they are not equal

			  }
		}

		if(equal==false){
			cout << "false" << endl;
		}
		else
		cout << "true" << endl;

	}
	return 0;
}
