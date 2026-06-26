class Solution{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Create buckets for counting sort
        int buckets[102] = {0};
        // Get frequency of each element
        for (int num : nums) {
            buckets[num]++;
        }
        // Count smaller numbers than each element
        for (int i = 1; i < 102; i++) {
            buckets[i] += buckets[i - 1];
        }
        // Populate the result
        vector<int> result(nums.size());
        for (int i = 0; i < result.size(); i++) {
            if (nums[i] == 0)
                result[i] = 0;
            else
                result[i] = buckets[nums[i] - 1];
        }
        return result;
    }
};