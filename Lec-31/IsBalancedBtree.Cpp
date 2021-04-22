#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{    ///root is NULL, then h =0 and balanced is true
    if(root==NULL){
        return {0,true};
    }

    ///check if left subtree is balanced or not and what is its height
    pair<int,bool> p1 = isHeightBalancedOptimised(root->left);

      ///check if right subtree is balanced or not and what is its height
    pair<int,bool> p2 = isHeightBalancedOptimised(root->right);

    int h=max(p1.first,p2.first)+1; /// height of current tree
    ///check if height difference between l and r is <=1
    if(abs(p1.first-p2.first)>1)
    return {h,false} ;

    ///return the or of left and right subtree
    if(p1.second ==false || p2.second==false)
         return {h,false} ;

    ///when height difference is <=1  for this node and left and right is balanced
    return {h,true};

    // return {h,p1.second && p2.second};

}

int main()
{
    node *root = build("true");

    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}

