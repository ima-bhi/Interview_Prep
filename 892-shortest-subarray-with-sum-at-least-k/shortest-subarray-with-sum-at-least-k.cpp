class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        //step 1: generate cummulative sum i.e used during sliding window
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        // use b/c monotonic approach is efficient in this 
        deque<int> dq;
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {

            // Check if we found a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            // default push
            dq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};