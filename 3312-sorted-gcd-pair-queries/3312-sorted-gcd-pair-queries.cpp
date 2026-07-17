class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;
        vector<long long> cntG(mx + 1, 0);
        for (int i = mx; i >= 1; i--) {
            long long cnt = 0;
            for (int j = i; j <= mx; j += i) {
                cnt += freq[j];
                cntG[i] -= cntG[j];
            }
            cntG[i] += cnt * (cnt - 1) / 2;
        }
        for (int i = 2; i <= mx; i++)
            cntG[i] += cntG[i - 1];
        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (cntG[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};