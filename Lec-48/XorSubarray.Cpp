///problem link:https://practice.geeksforgeeks.org/problems/a512e4b2e812b6df2159b19cc7090ffc1ab056dd/1/#

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
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






class Solution{
public:
    int maxSubarrayXOR(int N, int arr[]){
          int ans =0;
          ans = arr[0];
          for(int i=1;i<N;i++){
              arr[i]=(arr[i-1]^arr[i]);
              ans = max(ans,arr[i]);  ///max xor can be from 0th index too
          }
          TrieNode* root =new TrieNode();
          for(int i=0;i<N;i++){
              insert(root,arr[i]);
              ans = max(ans,search(root,arr[i]));  ///find the value of z so that
                                                  ///x^z is maximised
                                                  ///x is arr[i]
                                                  ///z is some value in arr(after prefix)

          }

          return ans;







    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0;
}
  // } Driver Code Ends
