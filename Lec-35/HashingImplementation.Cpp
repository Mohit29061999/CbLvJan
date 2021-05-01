#include <iostream>
using namespace std;


class Node{
public:
    string key; ///name of the fruit
    int val;   ///price of the fruit
    Node* next;   ///link to the next fruit that maps at this index

    Node(string s,int v){
        key=s;
        val = v;
        next = NULL;
    }
};


class Hashing{
private:
    Node** arr; ///it will point to the hash table
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
        ///create a new array of twice the previous size
        Node** oldArr= arr;  ///to store the link of previous array
        int pts=ts;
        ts=ts*2;  ///new array is double of previous
        arr = new Node*[ts];
        cs=0;  ///size should be 0 as it is newly created
        //copy contents of old array to new array
        for(int i=0;i<pts;i++){  ///for all index
            Node* n =oldArr[i]; ///head of linked list at that index
            while(n){
               insert(n->key,n->val);
                n=n->next;
            }
        }

        delete[] oldArr;


    }


public:

    Hashing(int size=7){
        arr = new Node*[size];  ///create an array of Node* of size given by user
        ts=size;
        cs=0;
        for(int i=0;i<ts;i++)
            arr[i]=NULL;  ///all the head are pointing to null

    }

    void insert(string key,int val ){
        cs++;
        ///ask for the index of the given key
        int index = hashFunc(key);
        Node* n =new Node(key,val);
        n->next = arr[index];  ///insert at head
        arr[index]=n; ///n is new head for this index

        ///check if hash table is 60% filled
        if((cs*1.0/ts)>=0.6){
            rehashing();  ///create a new table of twice the size
        }



    }

    Node* search(string key){
        int index= hashFunc(key);

        Node* n =arr[index]; ///get linked list corresponding to this index
        while(n){
            if(n->key==key)
                return n;
            n=n->next;
        }
        return NULL;


    }


    void print(){ ///print
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

    }

    int& operator[](string key){
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
    }


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
    Node* n =h.search(s);

    h["Apple"] = 150;  ///change value to a key
                           ///insert the value with this key

    cout << h["guava"] << endl;  ///search with that operator
   /*  string s;
     cin>>s;
    Node* n =search(s);
    if(n!=NULL)
        cout << n->val << endl;
    else
        cout << "doesn't exist" << endl; */

    h.print();

}
