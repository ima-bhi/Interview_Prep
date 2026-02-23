class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use unordered_map b/c we don't need sort data
        unordered_map<int, int> num_map;
        int n = nums.size();
        //iterate over array
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            
            // check diff is available or not  - boolean
            if (num_map.count(diff)) {
                return {num_map[diff], i};
            }

            //push value on map 
            num_map[nums[i]] = i;
        }
        return {}; // if no solution found
    }
};