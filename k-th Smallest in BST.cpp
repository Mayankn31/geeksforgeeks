/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void order(Node* root,vector<int>& in){
        if(root==NULL) return;
        order(root->left,in);
        in.push_back(root->data);
        order(root->right,in);
    }
    int kthSmallest(Node *root, int k) {
        vector<int>in;
        order(root,in);
        if(in.size()<k) return -1;
        return in[k-1];
    }
};


