#include <iostream>
using namespace std;

class TrieNode{
public:
  TrieNode* child[256];
  ///unordered_map<char,TrieNode*>m

    bool isEnd;

    TrieNode(){
         ///make all child as NULL
         for(int i=0;i<256;i++)
            child[i]=NULL;

         isEnd = false;  ///it is not last character of any word
    }
};


///insert a word in trie
void insert(TrieNode* root,string word){
    int n=word.length();
    TrieNode* curr = root;  ///initial position
    for(int i=0;i<n;i++){
        int index=word[i];

        if(curr->child[index]==NULL){  ///curr->child[index] to curr->m[word[i]]
                                          ///(curr->m).find(word[i])==curr->m.end()
            ///if the index child of current node,doesn't exist then create it
            curr->child[index]=new TrieNode();
        }
        curr = curr->child[index];  ///curr->child[index] to curr->m[word[i]]


    }

    curr->isEnd=true;  ///this node is the ending point of current word

}

///to search a word in trie
bool search(TrieNode* root,string word){
    int n=word.length();
    TrieNode* curr = root;  ///initial position
    for(int i=0;i<n;i++){
        int index=word[i];

        if(curr->child[index]==NULL){
             return false;  ///word doesn't exist
        }
        curr = curr->child[index];


    }

     if(curr->isEnd==false)
        return false;  ///this word is present but as a prefix to some word
     return true;

}

///to print all suggestion
void printRec(TrieNode* root,string curr){

              ///base case
              if(root->isEnd){
                cout << curr << endl;
              }

              ///go to all existing child of this node
              curr+='.';  ///temparory value
              for(int i=0;i<256;i++){
                if(root->child[i]!=NULL){
                        ///curr+=i;
                    curr[curr.length()-1]=(char)i;  ///changing last char
                    printRec(root->child[i],curr);
                }
              }
}

///auto complete
///to search a word in trie
void suggestion(TrieNode* root,string word){
    int n=word.length();
    TrieNode* curr = root;  ///initial position
    for(int i=0;i<n;i++){
        int index=word[i];

        if(curr->child[index]==NULL){
             return;
        }
        curr = curr->child[index];


    }

    ///now suggest item
    string curr_string= word;

     printRec(curr,curr_string);


}

int main(){
    ///dummy node
    TrieNode* root=new TrieNode();  ///this will never change so no need to pass it as refrence

    insert(root,"aba");  ///time complexity of search and insert: O(length of word)
    insert(root,"abc");
    insert(root,"cde");
    insert(root,"efg");
    insert(root,"cdg");
    insert(root,"cgh");
    insert(root,"chi");
    insert(root,"cfg");
    insert(root,"abcd");
    insert(root,"acd");
    insert(root,"abefg");
    insert(root,"abz");


    /*string t;
    cin>>t;
    if(search(root,t)){
        cout << "word exist" << endl;
    }
    else
        cout << "doesn't exist" << endl; */

        suggestion(root,"");


}
