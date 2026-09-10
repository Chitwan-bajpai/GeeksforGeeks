
/*
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double maxValue=0;
        int n=val.size();
        vector<double>ratio;
        for(int i=0;i<n;i++){
            double rat=(double)val[i]/wt[i];
            ratio.push_back(rat);
        }
        vector<pair<pair<int,int>,int>>frack;
        for(int i=0;i<n;i++){
            frack.push_back({{ratio[i],val[i]},wt[i]});
        }
        sort(frack.begin(),frack.end());
        int w=0,maxVal=0;
        for(auto fr:frack){
           // int weight=fr.second;
           int v=fr.first.second;
           int weight=fr.second;
            if(w>capacity){
                w=v*(capacity/w);
            }
            w=weight;
            maxVal+=w*v;
        }
        return maxVal;
    }
};
*/

class Solution {
public:
    double fractionalKnapsack(vector<int>& val,
                              vector<int>& wt,
                              int capacity) {

        double maxValue = 0;
        int n = val.size();

        vector<double> ratio;

        for (int i = 0; i < n; i++) {
            double rat = (double)val[i] / wt[i];
            ratio.push_back(rat);
        }

        vector<pair<pair<double, int>, int>> frack;

        for (int i = 0; i < n; i++) {
            frack.push_back({{ratio[i], val[i]}, wt[i]});
        }

        // Highest ratio first
        sort(frack.begin(), frack.end(), greater<>());

        for (auto fr : frack) {

            double rat = fr.first.first;
            int v = fr.first.second;
            int weight = fr.second;

            if (weight <= capacity) {

                // Take complete item
                maxValue += v;
                capacity -= weight;

            } else {

                // Take fraction
                maxValue += capacity * rat;
                break;
            }
        }

        return maxValue;
    }
};