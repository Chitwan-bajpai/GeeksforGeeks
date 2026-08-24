/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
       queue<pair<Node*,int>>q;
       if(root==NULL){
           return {};
       }
       map<int,int>mp;  //<HorizontalDistance,node val>
       vector<int>ans;
       q.push({root,0});
       
       while(!q.empty()){
           Node *curr=q.front().first;
           int currHD=q.front().second;
           q.pop();
           
           if(mp.find(currHD)==mp.end()){
               mp[currHD]=curr->data;
           }
           if(curr->left) q.push({curr->left,currHD-1});
           if(curr->right) q.push({curr->right,currHD+1});
       }
       for(auto x:mp){
           ans.push_back(x.second);
       }
       return ans;
        
    }
};