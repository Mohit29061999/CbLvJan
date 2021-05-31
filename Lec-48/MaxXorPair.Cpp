///problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
using namespace std;

class TrieNode{
public:
  TrieNode* child[2];  ///two child one for each bit


    TrieNode(){
         ///make all child as NULL
         for(int i=0;i<2;i++)
            child[i]=NULL;


    }
};


///insert a word in trie
void insert(TrieNode* root,int x){

    TrieNode* curr = root;  ///initial position

    ///convert it to binary
    for(int i=31;i>=0;i--){
        int y=(1<<i); ///this is a no with ith bit set only
        //check if ith bit is set or not
        int z=(x&y);
        if(z>0){
            ///check the right bit ie.1
            if(curr->child[1]==NULL){
                curr->child[1] = new TrieNode();
            }
            curr=curr->child[1];
        }
        else{
             ///check the left bit ie.0
            if(curr->child[0]==NULL){
                curr->child[0] = new TrieNode();
            }
            curr=curr->child[0];
        }


    }


}

///to find maximum xor with x
int  search(TrieNode* root,int x){

    TrieNode* curr = root;  ///initial position
    int ans =0;
       ///convert it to binary
    for(int i=31;i>=0;i--){

        int y=(1<<i); ///this is a no with ith bit set only
        //check if ith bit is set or not
        int z=(x&y);
        if(z>0){
            ///first check for 0 bit
            if(curr->child[0]!=NULL){
                ans+=y;  ///add contribution due to this bit
                curr = curr->child[0];
            }
            else{
                 curr=curr->child[1];
            }



        }
        else{
               ///first check for 1 bit
            if(curr->child[1]!=NULL){
                ans+=y;  ///add contribution due to this bit
                curr = curr->child[1];
            }
            else{
                 curr=curr->child[0];
            }
        }


    }

    return ans;


}







class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        int ans =0;
        TrieNode* root = new TrieNode();
    for(int i=0;i<n;i++)
        insert(root,nums[i]);  ///insert all the no in the trie

        for(int i=0;i<n;i++){
            ans = max(search(root,nums[i]),ans);  ///max xor from ith no
        }

        return ans;
    }
};
