class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> answer;
        for (auto it : nums1) {
            if (!st.count(it))
                st.insert(it); // if it is not present in set , add it
        }
        for (auto it : nums2) {
            if (st.count(it)) {
                answer.push_back(it);
                st.erase(it);
            }
        }
        return answer;
    }
};