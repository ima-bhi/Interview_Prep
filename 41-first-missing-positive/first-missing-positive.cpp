class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //structing the arr
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // mark the value presence
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        //find first missing +ve number 
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        //default
        return n + 1;        
    }
};