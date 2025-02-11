class Solution {
  public:
    void order(Node* root,vector<int>& in){
        if(root==NULL) return;
        order(root->left,in);
        in.push_back(root->data);
        order(root->right,in);
      }
    bool isBST(Node* root) {
        vector<int>in;
        order(root,in);
        for(int i=1;i<in.size();i++){
            if(in[i]<in[i-1]) return false;
        }
        return true;
    }
};
