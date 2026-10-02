class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = i;
            bool direction = nums[i] > 0;
            while (true) {
                int nextSlow = nextIndex(nums, slow);
                if ((nums[slow] > 0) != direction || nextSlow == slow)
                    break;
                slow = nextSlow;
                int nextFast = nextIndex(nums, fast);
                if ((nums[fast] > 0) != direction || nextFast == fast)
                    break;
                if ((nums[nextFast] > 0) != direction)   
                    break;
                nextFast = nextIndex(nums, nextFast);
                if ((nums[nextFast] > 0) != direction || nextFast == nextIndex(nums, nextFast))
                    break;
                fast = nextFast;
                if (slow == fast)
                    return true;
            }
        }
        return false;
    }
};