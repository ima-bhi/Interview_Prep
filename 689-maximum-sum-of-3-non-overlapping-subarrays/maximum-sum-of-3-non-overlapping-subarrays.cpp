class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Compute sums of all subarrays of size k
        vector<int> W(n - k + 1, 0);
        W[0] = accumulate(nums.begin(), nums.begin() + k, 0);

        for (int i = 1; i < W.size(); i++) {
            W[i] = W[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        int m = W.size();

        // Step 2: bestLeftSumIdx[i] = index of max W in range [0..i]
        vector<int> bestLeftSumIdx(m, 0);
        for (int i = 1; i < m; i++) {
            if (W[i] > W[bestLeftSumIdx[i - 1]])
                bestLeftSumIdx[i] = i;
            else
                bestLeftSumIdx[i] = bestLeftSumIdx[i - 1];
        }

        // Step 3: bestRightSumIdx[i] = index of max W in range [i..end]
        vector<int> bestRightSumIdx(m, m - 1);
        for (int i = m - 2; i >= 0; i--) {
            if (W[i] >= W[bestRightSumIdx[i + 1]])
                bestRightSumIdx[i] = i;
            else
                bestRightSumIdx[i] = bestRightSumIdx[i + 1];
        }

        // Step 4: Fix middle subarray and compute max total
        vector<int> ans(3, 0);
        int maxSum = 0;

        for (int j = k; j <= m - k - 1; j++) {
            int left = bestLeftSumIdx[j - k];
            int right = bestRightSumIdx[j + k];

            int total = W[left] + W[j] + W[right];

            if (total > maxSum) {
                maxSum = total;
                ans = {left, j, right};
            }
        }

        return ans;
    }
};