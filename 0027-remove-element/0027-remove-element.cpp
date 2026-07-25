class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //pointer to track valid index
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                //valid value
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};