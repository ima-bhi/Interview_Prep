class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch Flag Algo used
        // case 1:n[mid]==0 , swap l,r and increase pointer
        // case 2: n[mid]==1 , mid++ 
        int size = nums.size();
        int left = 0, mid = 0, right = size - 1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[left++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
                // case 3: el is equal to 2 -- swap mid with high
                // decrease the high
            } else {
                swap(nums[mid], nums[right--]);
            }
        }
    }
};