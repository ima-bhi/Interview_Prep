class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int minm = 0;
        if (n <= 2) {
            return 0;
        }
        // cretae left and right vector
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        right[n - 1] = height[n - 1];

        // calculate left and right
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
            right[n - 1 - i] = max(right[n - i], height[n - 1 - i]);
        }

        // for minm water shortage
        for (int i = 1; i < n; i++) {
            minm += min(left[i], right[i]) - height[i];
        }
        return minm;
    }
};