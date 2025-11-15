class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // write pointer

        for (int x : nums) {
            // as per the problem -- el twice value is allowed that means k-2 did n't
            // equal to current value
            if (k < 2 || x != nums[k - 2]) {
                // insert + increase k value
                nums[k++] = x;
            }
        }
        return k;
    }
};