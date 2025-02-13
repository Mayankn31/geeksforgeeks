// APPROACH 1
/* 
Node is as follows
class Node {
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
    bool solve(Node* root,int tar,unordered_set<int>& st){
        if(root==NULL) return false;
        if(st.find(tar-root->data)!=st.end()) return true;
        st.insert(root->data);
        bool l=solve(root->left,tar,st);
        bool r=solve(root->right,tar,st);
        return l||r;
    }
    bool findTarget(Node *root, int target) {
        unordered_set<int>st;
        return solve(root,target,st);
    }
};




// APPROACH 2

/*Complete the function below
Node is as follows
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

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void solve(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    
    int isPairPresent(struct Node *root, int target){
        vector<int>v;
        solve(root,v);
        
        int size=v.size();
        int i=0,j=size-1;
        
        while(i<j){
            if(v[i]+v[j]==target){
                return 1;
            }
            else if(v[i]+v[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return 0;
    }
};
