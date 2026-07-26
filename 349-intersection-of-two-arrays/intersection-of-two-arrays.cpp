class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //set for uniq num
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> common;
        //iteate over num2 and check if element present or not.
        for (auto it : nums2) {
            if (st.count(it)) {
                common.push_back(it);
                st.erase(it);
            }
        }
        return common;
    }
};