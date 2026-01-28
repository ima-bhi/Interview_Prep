class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int num : nums) {
            // initialize candidate
            if (count == 0) {
                candidate = num;
            }
            // if num is same -- increase count
            if (num == candidate) {
                count++;
            } else {
                // else decrement counter
                count--;
            }
        }

        return candidate;
    }
};