class Solution {
  public:
    vector<int> remDuplicate(vector<int>& arr) {
        // code here
        unordered_set<int>s;
        vector<int>ans;
        
        for(int x:arr){
            if(s.find(x)==s.end()){
                s.insert(x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};