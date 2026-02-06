class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Result vector to store duplicate numbers
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) { 
                result.push_back(index + 1); // Add the duplicate number to the result
            } else {
                nums[index] = -nums[index]; // Mark the number as seen by negating it
            }
        }
        return result; 
    }
};