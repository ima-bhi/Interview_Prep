class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int larg = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            //edge case
            if (curr < 0) {
                curr = 0;
            }
            curr = curr + nums[i];
            //find larg
            larg = max(larg, curr);
        }
        return larg;
    }
};