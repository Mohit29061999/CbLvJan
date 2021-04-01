
#include <iostream>
#include <vector>   //using stl vector
using namespace std;




int main(){
   vector<int> v;
   for(int i=0;i<5;i++){
        int x;
   cin>>x;
    v.push_back(x);
   }
   v.push_back(30);

    for(int i=0;i<5;i++)
      cout << v[i] << " ";
      cout << endl;
    cout << v.size() << endl;

   for(int i=0;i<5;i++)
    v.pop_back();
    cout << v.size() << endl;


}

