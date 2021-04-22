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
class BSTIterator {
    stack<TreeNode* >s;
public:
    BSTIterator(TreeNode* root) {
        ///insert the first value in in-order traversal at top of the stack
        TreeNode* cur = root;
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
    }

   TreeNode* next() {
        ///print the current value and insert the next value in inorder
        ///traversal at the top of the stack
        TreeNode* cur = s.top();
        s.pop();
        ///val of current is stored in x
        int x=cur->val;

        ///insert the next value in stack which is leftmost value
        ///in the right subtree of this node
        cur = cur->right;
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        return x;
    }

    bool hasNext() {
        ///check if stack is empty or not
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
