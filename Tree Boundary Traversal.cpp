/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftNode(Node* root,vector<int>& ans){
        if(root==NULL || (root->right==NULL && root->left==NULL)) return;
        ans.push_back(root->data);
        leftNode(root->left,ans);
        if(root->left==NULL) leftNode(root->right,ans);
    }
    void leafNode(Node* root,vector<int>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        leafNode(root->left,ans);
        leafNode(root->right,ans);
    }
    void rightNode(Node* root,vector<int>& ans){
        if(root==NULL || (root->right==NULL && root->left==NULL)) return;
        rightNode(root->right,ans);
        if(root->right==NULL) rightNode(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        ans.push_back(root->data);
        leftNode(root->left,ans);
        leafNode(root->left,ans);
        leafNode(root->right,ans);
        rightNode(root->right,ans);
        return ans;
    }
};
