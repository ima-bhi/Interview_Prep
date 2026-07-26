class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int larg = nums[0], cSum = nums[0]; // cSum - current Sum
        for (int i = 1; i < nums.size(); i++) {
            if (cSum < 0) {
                cSum = 0; // Previous subarray is useless, start a new one
            }

            cSum += nums[i];
            larg = max(larg, cSum);
        }
        return larg;
    }
};