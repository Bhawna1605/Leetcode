class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        // freq array to count occurrences
        int freq[100001] = {0};
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }    
        // collect elements with freq == 2
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};