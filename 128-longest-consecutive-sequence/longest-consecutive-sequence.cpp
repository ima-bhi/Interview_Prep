class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // store unique el
        set<int> st(nums.begin(), nums.end());

        int maxCount = 1, count = 1;
        bool first = true;
        int prev = 0;

        // Step 2: iterate using for-each loop
        for (int curr : st) {
            //first el entry
            if (first) {
                prev = curr;
                first = false;
                continue;
            }

            if (curr - prev == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 1;
            }

            prev = curr;
        }

        // final update
        maxCount = max(maxCount, count);

        return maxCount;
    }
};