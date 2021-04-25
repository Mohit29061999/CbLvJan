///problem link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        stack<TreeNode*>l,r;  /// l is pointing to min value and r is pointing to max value
        TreeNode* curr=root;
        ///store min value at top of stack
        while(curr){
            l.push(curr);
            curr=curr->left;
        }

        curr=root;
          ///store max value at top of stack
        while(curr){
            r.push(curr);
            curr=curr->right;
        }

        while(l.top() !=r.top()){
            TreeNode* c1=l.top();
            TreeNode* c2=r.top();
            if(c1->val + c2->val ==k)
                return true;
            if(c1->val + c2->val >k){
                //r--;
                r.pop();
                ///insert the next max value
                c2 = c2->left;
                while(c2){
                    r.push(c2);
                    c2=c2->right;
                }
            }

            else{
                ///l++;
                    //r--;
                l.pop();
                ///insert the next max value
                c1 = c1->right;
                while(c1){
                    l.push(c1);
                    c1=c1->left;
                }
            }

        }

        return false;

    }
};
