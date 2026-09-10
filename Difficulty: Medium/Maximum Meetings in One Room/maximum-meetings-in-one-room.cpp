class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
       vector<pair<pair<int,int>,int>>meetings;
       vector<int>ans;
       int n=s.size();
       for(int i=0;i<n;i++){
           meetings.push_back({{f[i],i+1},s[i]});
       }
       
       sort(meetings.begin(),meetings.end());
       
       int lastFinish=-1;
       for(auto meeting:meetings){
           int finish=meeting.first.first;
           int index=meeting.first.second;
           int start=meeting.second;
           if(start>lastFinish){
               ans.push_back(index);
               lastFinish=finish;
           }
           
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};