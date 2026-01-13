class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tProduct = 1;
        int zeroCount = 0, idx = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
                idx = i;
            } else {
                tProduct *= nums[i];
            }
        }

        vector<int> v(n, 0);

        if (zeroCount > 1) {
            // all zeros
            return v;
        } else if (zeroCount == 1) {
            // only one index has product
            v[idx] = tProduct;
            return v;
        } else {
            // no zeros
            for (int i = 0; i < n; i++) {
                v[i] = tProduct / nums[i];
            }
            return v;
        }
    }
};
