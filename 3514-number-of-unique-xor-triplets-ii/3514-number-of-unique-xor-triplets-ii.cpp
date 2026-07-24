class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        int T = 1;
        while(T <= maxEl) {
            T <<= 1; //T = T*2
        }
        vector<bool> s1(T, false); //XOR pair values set to true
        vector<bool> s2(T, false); //XOR triplet values set to true
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        for(int i = 0; i < T; i++) {
            if(s1[i] == true) {
                for(int &num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }
        int count = 0; //unique xor count
        for(int i = 0; i < T; i++) {
            if(s2[i] == true)
                count++;
        }
        return count;
    }
};