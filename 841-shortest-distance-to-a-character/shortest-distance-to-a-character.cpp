class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> occur;
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                occur.push_back(i);
        }
        for (int i = 0; i < s.size(); i++) {
            int dist = INT_MAX;
            for (int j = 0; j < occur.size(); j++) {
                dist = min(dist, abs(i - occur[j]));
            }
            ans.push_back(dist);
        }
        return ans;
    }
};