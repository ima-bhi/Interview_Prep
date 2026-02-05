class Solution {
public:
    /*
    step 1: find the decreasing element first from the end (breakpoint)
    step 2: if no breakpoint found -- reverse the array
    step 3: if there is breakpoint -- find the smallest element from end which
    is greater than first decreasing element and swap it
    step 4 : reverse the list from idx (decreasing) to the end
     */
    void nextPermutation(vector<int>& nums) {
        // step 1. find the breakpoint
        int ind = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        // if no break point found
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // swap the beakpoint
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }

            // reverse the rested sorted array
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};