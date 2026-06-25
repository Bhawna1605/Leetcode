class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddPtr=1;//points to odd index needing an odd number
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]%2!=0){
                //if even index has odd number-fix it
                while(nums[oddPtr]%2!=0){
                    oddPtr+=2;
                }
                int temp=nums[i];
                nums[i]=nums[oddPtr];
                nums[oddPtr]=temp;
            }
        }
        return nums;
    }
};