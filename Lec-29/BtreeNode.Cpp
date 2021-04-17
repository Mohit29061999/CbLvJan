#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

///code for pre-order traversal (root,left subtree,right subtree)
void preOrder(Node* root){
    ///base case
    if(root==NULL)
        return;

    cout << root->val << " ";

    ///print the left subtree
    preOrder(root->left);

    ///print the right subtree
    preOrder(root->right);
}


///code for in-order traversal (left subtree,root,right subtree)
void inOrder(Node* root){
    ///base case
    if(root==NULL)
        return;


    ///print the left subtree
    inOrder(root->left);


    cout << root->val << " ";
    ///print the right subtree
    inOrder(root->right);
}

///code for post-order traversal (left subtree,right subtree,root)
void postOrder(Node* root){
    ///base case
    if(root==NULL)
        return;


    ///print the left subtree
    postOrder(root->left);
    ///print the right subtree
    postOrder(root->right);
    cout << root->val << " ";
}

///make a function to create the tree
Node* createTree(){
    int data;
    cin>>data;

    //if data is -1 then it is NULL
    if(data==-1)
        return NULL;

    ///create the node with current data
    Node* root = new Node(data);

    ///create the left subtree
    root->left=createTree();

    ///create the right subtree
    root->right = createTree();
    return root;

}

void levelOrderTraversal(Node* root){
    if(root==NULL)
    return;

    queue<Node*>q;
    q.push(root);

    ///while queue is non-empty,print the node present at the front and then insert its child in queue
    ///left then right
    while(!q.empty()){
        //print a level in one run
        int s=q.size();  ///number of nodes in current level
       for(int i=0;i<s;i++){
        Node* n =q.front();
         q.pop();
        cout << n->val << " ";

        ///check if left is not NULL then insert it
        if(n->left!=NULL){  ///when condition is not mentioned then it is assumed it is true
            q.push(n->left);  ///null means false , not NULL means true
        }

         ///check if right is not NULL then insert it
        if(n->right){
            q.push(n->right);
        }

       }
       cout << endl;
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;



    ///get height of left subtree
    int l_height = height(root->left);

    ///get height of right subtree
    int r_height = height(root->right);

    return max(l_height,r_height)+1;  ///+1 for root

}

Node* createTreeFromlevelOrderTraversal(){
   int data;
   cin>>data;
   if(data ==-1)
    return NULL;
   Node* root = new Node(data);  ///i am creating the root

    queue<Node*>q;
    q.push(root);

    ///while queue is non-empty,print the node present at the front and then insert its child in queue
    ///left then right
    while(!q.empty()){
       Node* n = q.front();  ///remove the front node of the queue and create its child
       q.pop();

       ///val of left child
       cin>>data;

       ///if data is -1 then it is NULL so don't create it
       if(data !=-1){
          Node* newNode = new Node(data);
          n->left = newNode;
          ///insert the left child to the queue
          q.push(newNode);
       }

       ///create the right child

        ///val of right child
       cin>>data;

       ///if data is -1 then it is NULL so don't create it
       if(data !=-1){
          Node* newNode = new Node(data);
          n->right = newNode;
          ///insert the right child to the queue
          q.push(newNode);
       }
    }
    return root;
}

///to search a value in the tree
Node* search(Node* root,int key){
    if(root==NULL)
        return NULL;
    if(root->val == key)
        return root;

    Node* l = search(root->left,key);
    if(l!=NULL)
        return l;

    Node* r = search(root->right,key);
     return r;

}

int main(){
Node* root =NULL;   ///it will store the address of the first node or root
//root = createTree();
root = createTreeFromlevelOrderTraversal();

//preOrder(root);
//inOrder(root);
Node* x=search(root,10);
if(x!=NULL)
    cout << x->val << endl;
else
    cout << "Not Found" << endl;
//postOrder(root);

//levelOrderTraversal(root);
//cout << height(root) << endl;
}
