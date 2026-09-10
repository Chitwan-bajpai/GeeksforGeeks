class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<int>ans;
        vector<pair<pair<int,int>,int>>activities;
        int n=start.size();
        for(int i=0;i<n;i++){
            activities.push_back({{finish[i],i+1},start[i]});
        }
        
        sort(activities.begin(),activities.end());
        int lastFinish=-1;
        
        for(auto activity:activities){
            int finish=activity.first.first;
            int index=activity.first.second;
            int start=activity.second;
            
            if(start>lastFinish){
                ans.push_back(index);
                lastFinish=finish;
            }
        }
        sort(ans.begin(),ans.end());
        return ans.size();
    }
};