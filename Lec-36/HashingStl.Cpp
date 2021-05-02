
#include <iostream>
#include <map>  ///for normal map  //items are arranged in order by key
#include <unordered_map>  ///for unordered_map
using namespace std;


int main(){
    unordered_map<string,int>m;  /// first data type will be key,second data will be value
    m["Mango"]=100; ///inserting a value
    m["Guava"]=200;
    m["Banana"]=60;
    m["Pineapple"]=200;
    m["Mango"]=250;  ///updating a key
   //m.insert({"apple",100});
    ///to search  a key in map
    ///find tells you key exist or not
    ///find is returning NULL that means value doesn't exist else it exist
    if(m.find("Mango")!=m.end()){
         cout << m["Mango"] << endl;  //searching
    }
   cout << (m.begin())->first << endl;

    ///travel through the map based on key value
   /// m.begin() ->gives you the node with minimum key

   /* for(map<string,int>::iterator it = m.begin();it!=m.end();it++){
        cout << it->first << " " << it->second << endl;
    }  */
     m.erase("Mango");  ///it remove a key from map
     ///creates the iterator of the ds that you are using
     for(auto it = m.begin();it!=m.end();it++){
        cout << it->first << " " << it->second << endl;
    }

}
