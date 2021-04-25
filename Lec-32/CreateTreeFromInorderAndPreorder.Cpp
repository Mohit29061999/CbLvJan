//problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/// tells the index of root of current subtree in inorder traversal
int find(vector<int> &in,int val){
    int n=in.size();
    for(int i=0;i<n;i++){
        if(in[i]==val)
            return i;
    }
    return -1;
}

int index1 =0;

TreeNode* createTree(vector<int>& pre,vector<int>&in,int l,int r){
    ///base case: tree is already created
    int n=in.size();
    if(l>r || index1>=n)
        return NULL;
    cout << index1 << endl;
    TreeNode* root = new TreeNode(pre[index1]);
    index1++; ///next time use next value as root
    ///find the index of current root in the inorder traversal
    int x=find(in,root->val);
    ///all the values before this index they should be present in left of this node
    root->left = createTree(pre,in,l,x-1);

     ///all the values after this index they should be present in right of this node
    root->right = createTree(pre,in,x+1,r);

    return root;

}


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        index1=0;
        return createTree(preorder,inorder,0,n-1);
    }
};
