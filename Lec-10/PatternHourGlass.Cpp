#include<iostream>
using namespace std;


int main() {
	int n;
	cin>>n;

	int cntn=2*n+1 ;  //count of number to be printed,for first row it is 2*n+1
	int cnts=0;       //count of space to be printed  for first row it is 0

	for(int row=1;row<=n+1;row++){
        int val=n-row+1;  //first value to be printed in every row
	   //print space
	   for(int space=1;space<=cnts;space++){
           cout << "  ";
	   }
	   bool flag=true;  //tells whether to increase or decrease the number
	   //flag == true means decrease the number
	   for(int i=1;i<=cntn;i++){
		   cout << val << " ";
		   //if value is 0 then change flag
		   if(val==0)
		   flag =false;
		   if(flag==false){
              val++;
		   }
		   else{
			   val--;
		   }
	   }

	   //go to next row;
	   cntn-=2;
	   cnts++;
	   cout << endl;
	}

	//printing lowerhalf pattern
	cntn=3;
	//print n rows
	for(int row=1;row<=n;row++){
		int val = row;  //first value in every row for lower half
		//print n-row spaces
		for(int space=1;space<=n-row;space++)
		cout << "  ";

		   bool flag=true;  //tells whether to increase or decrease the number
	   //flag == true means decrease the number

		for(int i=1;i<=cntn;i++){
			cout << val << " ";

			 //if value is 0 then change flag
		   if(val==0)
		   flag =false;
		   if(flag==false){
              val++;
		   }
		   else{
			   val--;
		   }

		}

		//go to next row
		cntn+=2;
		cout << endl;
	}

	return 0;
}
