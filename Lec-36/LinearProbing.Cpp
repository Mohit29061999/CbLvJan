#include <iostream>
#include <bits/stdc++.h>
using namespace std;



///arr of pair(key,value)

class Hashing{
private:
    string temp;
    string deleted;
    pair<string,int>* arr; ///it will point to the hash table  ///pair<int,int>* arr;  ///pointer to point to array of pairs
    int cs;  ///number of elements in hash table
    int ts;   ///total size of hash table

    int hashFunc(string key){
        ///give you a index in the hash table
        int ans =0;  ///index
        int mul =1 ;  ///29^0
        int n=key.length();
        for(int i=0;i<n;i++){
            ans+=((key[i]*mul)%ts);
            ans = ans%ts;
            mul = mul*29;
        }

        return ans; ///to get values in table range

    }

    void rehashing(){
        pair<string,int>* oldArr;///create a new array of twice the previous size
       oldArr= arr;  ///to store the link of previous array
        int pts=ts;
        ts=ts*2;  ///new array is double of previous
        arr = new pair<string,int>[ts];
        ///all the slots are empty
        for(int i=0;i<ts;i++){
            arr[i]={temp,-1};  ///-1 means empty slot
        }
        cs=0;  ///size should be 0 as it is newly created
        //copy contents of old array to new array
        for(int i=0;i<pts;i++){  ///for all index

           if(oldArr[i].first!=temp && oldArr[i].first!=deleted){
               insert(oldArr[i].first,oldArr[i].second);
           }
        }

        delete[] oldArr;


    }


public:

    Hashing(int size=7){
        temp="@";  ///symbol for empty cell
        deleted = "*";  ///symbol for deleted cell
        arr = new pair<string,int>[size];  ///create an array of Node* of size given by user
        ts=size;
        cs=0;
        for(int i=0;i<ts;i++)
            arr[i]={temp,-1};  ///-1 means empty slot

    }

    void insert(string key,int val ){
        cs++;
        ///ask for the index of the given key
        int index = hashFunc(key);

        while(true){
                string x=arr[index].first;
             if(x==temp)
                break;
             if(x==deleted)
                break;
            index=(index+1)%ts;
        }

          arr[index]={key,val};  ///store at empty/deleted cell

        ///check if hash table is 60% filled
        if((cs*1.0/ts)>=0.6){
            rehashing();  ///create a new table of twice the size
        }



    }

   pair<string,int> search(string key){
        int index= hashFunc(key);

        ///in search deleted and empty they are different
        ///you have to stop at -1 only

         ///ask for the index of the given key
       // int index = hashFunc(key);

        while(true){
                string x=arr[index].first;
             if(x==temp)
                break;
            if(x==key){

                return arr[index];
            }

            index=(index+1)%ts;
        }

        return {temp,-1};



    }


   /* void print(){ ///print
        ///this will be O(n) operation
        for(int i=0;i<ts;i++){
            cout << i<<"---";
            Node* n = arr[i];
            while(n){
                cout << n->key << "  ";
                n=n->next;
            }
            cout << endl;
        }

    } */

   /* int& operator[](string key){
        ///search if that key exits or not
        Node* n = search(key);
        if(n!=NULL){
            return n->val;
        }
        else{
            insert(key,-1);
            Node* n1=search(key);
            return n1->val;
        }
    } */


};

int main(){
    Hashing h;
    h.insert("Mango",100);
    h.insert("apple",120);
    h.insert("kiwi",200);
    h.insert("grape",150);
    h.insert("banana",60);
    h.insert("pineapple",200);
    h.insert("guava",250);

    string s;
    cin>>s;

    pair<string,int> p = h.search(s);
    if(p.first!="@"){
        cout << p.first << " " << p.second << endl;
    }
    else
        cout << "doesn't exist" << endl;
 //   Node* n =h.search(s);

  //  h["Apple"] = 150;  ///change value to a key
                           ///insert the value with this key

   // cout << h["guava"] << endl;  ///search with that operator
   /*  string s;
     cin>>s;
    Node* n =search(s);
    if(n!=NULL)
        cout << n->val << endl;
    else
        cout << "doesn't exist" << endl; */


    //h.print();



}

