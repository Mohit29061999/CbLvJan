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
class data1{
    public:
    bool isBst;
    int max_v;
    int min_v;
    int sum;

    data1(bool b,int f,int s,int t){
        isBst = b;
        max_v=s;
        min_v=f;
        sum =t;
    }
};

data1 maxSumBst1(TreeNode* root,int &res1){
    ///base case
    if(root==NULL){
        data1 d(true,INT_MAX,INT_MIN,0);
        return d;

    }

    ///ask for the value from left side
    data1 d1=maxSumBst1(root->left,res1);

        ///ask for the value from right side
    data1 d2=maxSumBst1(root->right,res1);

    data1 res(true,0,0,0);  ///to store the answer for the current node
    res.sum = d1.sum+d2.sum+root->val;
    res.min_v=min(root->val,min(d1.min_v,d2.min_v));
    res.max_v=max(root->val,max(d1.max_v,d2.max_v));

    if(d1.isBst==false || d2.isBst==false){
        ///this subtree is not a bst
        res.isBst = false;
        return res;
    }

    ///if both left and right subtree is bst then check if root->val>max in left and root->val<min in right
    if(root->val>d1.max_v && root->val<d2.min_v){
         ///this subtree is  a bst
        res.isBst = true;
        res1=max(res1,res.sum);
        return res;
    }

     ///this subtree is not a bst
        res.isBst = false;
        return res;


}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int res=0;
        maxSumBst1(root,res);
        return res;

    }
};
