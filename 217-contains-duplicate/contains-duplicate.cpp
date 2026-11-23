class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = nums[0];
        if (nums.size() == 1)
            return false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == start) {
                return true;
            } else {
                start = nums[i];
            }
        }
        return false;
    }
};