#include<iostream>
#include <algorithm> //header file for pair
using namespace std;



int main ()
{
    pair<int,int>p1={4,5};
      pair<int,int>p2={5,5};
      pair<int,int> arr[100];
      arr[0]={12,15};
      cout << arr[0].first << " " << arr[0].second << endl;

      if(p1<p2)
        cout << "p2 is greater" << endl;
      else
        cout << "No" << endl;

    p1.first =10;
   // p.second =5;

   if(p1<p2)
        cout << "p2 is greater" << endl;
      else
        cout << "No" << endl;



}

