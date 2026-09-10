class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int maxTime=0;
        for(int i=0;i<mices.size();i++){
            int Time=abs(mices[i]-holes[i]);
            maxTime=max(maxTime,Time);
        }
        return maxTime;
    }
};