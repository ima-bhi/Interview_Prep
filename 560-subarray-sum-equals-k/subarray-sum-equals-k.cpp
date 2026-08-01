class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // initalize map to store el
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        // set 0 idx to 1 b/c array is contiguous
        mp[0] = 1;
        for (auto it : nums) {
            sum += it;
            int find = sum - k;
            if (mp.find(find) != mp.end()) {
                // store freq. of occured el
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};