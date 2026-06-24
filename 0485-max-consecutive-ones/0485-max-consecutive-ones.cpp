class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0;
        int current=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                current++;
                if(current>maxCount){
                    maxCount=current;
                }
            }
            else{
                current=0;
            }
        }
        return maxCount;
    }
};