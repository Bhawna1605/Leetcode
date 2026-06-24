class NumArray {
private:
    int* prefix;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        prefix = new int[n];
        if(n > 0) {
            prefix[0] = nums[0];

            for(int i = 1; i < n; i++) {
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
    ~NumArray() {
        delete[] prefix;
    }
};