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

int maxPath(TreeNode* root,int &res){
    if(root==NULL)
        return 0;

    int l =maxPath(root->left,res);
    int r=maxPath(root->right,res);

    //case i: root alone
    res = max(res,root->val);

    //case ii: root + left
    res = max(res,root->val+l);

    //case iii: root + right
    res = max(res,root->val+r);

     //case iv: root + right+left
    res = max(res,root->val+r+l);

    ///return only those cases that are useful for the parent
    int one = root->val;
    int temp = one;
    temp = max(temp,root->val+l);
    temp = max(temp,root->val+r);
    return temp;


}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res =INT_MIN;
        maxPath(root,res);
        return res;
    }
};
