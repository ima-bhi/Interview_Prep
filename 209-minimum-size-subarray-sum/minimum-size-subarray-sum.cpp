class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //initialize poiners
        int left = 0;
        int sum = 0;
        int minWindow = INT_MAX;

        // iterate over array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // if sum>=target -- means window found
            while (sum >= target) {
                sum -= nums[left];
                // store minimum window size
                minWindow = min(minWindow, i - left + 1);
                left++;
            }
        }
        // return result as per the window
        return minWindow == INT_MAX ? 0 : minWindow;
    }
};