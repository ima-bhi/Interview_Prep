class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            // if num is same -- increase count
            if (nums[i] == candidate) {
                count++;
            } else {
                // else decrement counter
                count--;
            }
        }

        return candidate;
    }
};