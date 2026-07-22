class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // storing {data :key , index}
        unordered_map<int, int> num_map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = target - nums[i];
            //finding left in map and return idx of left and current
            if (num_map.count(left)) {
                return {num_map[left], i};
            }
            //push value on map 
            num_map[nums[i]] = i;
        }
        return {}; // if no solution found
    }
};