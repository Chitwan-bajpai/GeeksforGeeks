class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int minCount=0;
        int maxCount=0;
        int n=prices.size();
        sort(prices.begin(),prices.end());
        /*for(int i=0;i<n/k;i++){
            minCount+=prices[i];
        }*/
        int i=0,j=n-1;
        while(i<=j){
            minCount+=prices[i];
            i++;
            j-=k;
        }
        i=0;
        j=n-1;
        while(i<=j){
            maxCount+=prices[j];
            j--;
            i+=k;
        }
        return {minCount,maxCount};
    }
};