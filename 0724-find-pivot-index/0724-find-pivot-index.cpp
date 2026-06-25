class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        // Pehle total sum nikalo
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        // Ab left sum track karte hue pivot dhundo
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = total - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;  // Pivot mil gaya
            }
            leftSum += nums[i];
        }
        return -1;  
    }
};