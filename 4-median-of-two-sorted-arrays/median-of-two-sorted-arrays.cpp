class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        //Initialize paramters
        int L1 = nums1.size(), L2 = nums2.size();
        int left = 0, right = 0;
        
        // step 1. Merge the two arrays
        
        while (left < L1 && right < L2) {
            if (nums1[left] < nums2[right]) {
                merge.push_back(nums1[left++]); // Use push_back
            } else {
                merge.push_back(nums2[right++]);
            }
        }
        while (left < L1) merge.push_back(nums1[left++]);
        while (right < L2) merge.push_back(nums2[right++]);

        // 2. Calculate Median
        int total = merge.size();
        
        if (total % 2 == 1) {
            // Odd case: Return the middle element
            return double(merge[total / 2]);
        } else {
            // Even case: Return average of the two middle elements
            double mid1 = merge[total / 2 - 1];
            double mid2 = merge[total / 2];
            return (mid1 + mid2) / 2.0;
        }
    }
};