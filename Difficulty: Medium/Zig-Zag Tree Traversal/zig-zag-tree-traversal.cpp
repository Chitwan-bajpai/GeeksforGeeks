/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
       vector<int> result;
       if(root==NULL){
           return result;
       }
       bool flag=true;
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           int size=q.size();
           vector<int>row(size);
           for(int i=0;i<size;i++){
               Node *temp=q.front();
               q.pop();
               int index= (flag) ? i:(size-1-i);
               
               row[index]=temp->data;
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
           flag!=flag;
           for(int val : row) result.push_back(val);
       }
       return result;
    }
};
*/
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == NULL) return result;

        bool flag = true;   // true = left-to-right
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                int index = flag ? i : (size - 1 - i);
                row[index] = temp->data;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            flag = !flag;
            for (int val : row) result.push_back(val);
        }
        return result;
    }
};