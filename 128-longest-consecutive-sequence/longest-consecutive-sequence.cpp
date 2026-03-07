class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        set<int> st(nums.begin(), nums.end());

        int maxCount = 1;
        for (int num : st) {
            if (!st.count(num - 1)) {
                int curr = num;
                int count = 1;
                while (st.count(curr + 1)) {
                    curr++;
                    count++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};