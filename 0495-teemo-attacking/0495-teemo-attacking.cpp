class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        sort(timeSeries.begin(),timeSeries.end());//in non decreasing order
        for(int i=1;i<timeSeries.size();i++){
            sum+=min(timeSeries[i]-timeSeries[i-1],duration);
        }
        return sum+duration;
    }
};