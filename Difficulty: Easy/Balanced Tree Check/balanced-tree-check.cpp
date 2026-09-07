/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
 
class Solution {
  public:
    int height(Node *root){
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL){
            return 1+height(root->right);
        }
        if(root->right==NULL){
            return 1+height(root->left);
        }
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(Node* root) {
        if(root==NULL) return true;
        int leftSub=height(root->left);
        int rightSub=height(root->right);
        if(abs(leftSub-rightSub)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};