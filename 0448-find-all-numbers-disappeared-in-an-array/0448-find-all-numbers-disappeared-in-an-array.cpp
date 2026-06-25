class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>missingNumbers;
        for(int i=0;i<nums.size();++i){
            while(nums[i]!=nums[nums[i]-1]){
                int temp=nums[i];
                nums[i]=nums[nums[i]-1];
                nums[temp-1]=temp;
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]-1!=i){
                missingNumbers.push_back(i+1);
            }
        }
        return missingNumbers;
    }
};