
#include <iostream>
#include <set>  ///for normal set  //items are arranged in order by key
#include <unordered_set> ///for unordered_set
using namespace std;

///in set you have key==value
int main(){
   unordered_set<int>s;

   s.insert(10);  ///m.insert({key,value})  ///m.insert(make_pair(key,value));
   s.insert(5);
   s.insert(1);
   s.insert(2);
   s.insert(15);

  // m["key"]=value;

   for(auto it=s.begin();it!=s.end();it++)
      cout << *it << endl;

      s.erase(5);  ///it will delete a key from set
    if(s.find(5)!=s.end()){  ///whether key exists or not
        cout << "5 exist" << endl;
    }
    else
        cout << "no it don't" << endl;






}

