#include<iostream>
#include <stack>
using namespace std;


int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];

  stack<int>s;
  int out[n];

  s.push(0);
  out[0]=1;

  for(int i=1;i<n;i++){
	  //remove all irrerevalant index
	  while(!s.empty()  && arr[s.top()]<=arr[i])
	  s.pop();

	  if(s.empty())
	  out[i]=i+1;
	  else
	  out[i]=i-s.top();
	  s.push(i);
  }

  for(int i=0;i<n;i++){
	  cout << out[i] << " ";
  }

  cout << "END" << endl;


}
