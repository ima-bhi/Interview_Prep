class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int n = s.length();
        string uniq(1, s[0]);
        string maxm(1, s[0]);

        for (int i = 1; i < n; i++) {

            int pos = uniq.find(s[i]);

            // duplicate found
            if (pos != string::npos) {
                if (uniq.size() > maxm.size()) {
                    maxm = uniq;
                }
                // remove characters up to duplicate
                uniq.erase(0, pos + 1);
            }
            // add current character
            uniq.push_back(s[i]);
        }

        // final comparison (VERY IMPORTANT)
        if (uniq.size() > maxm.size()) {
            maxm = uniq;
        }

        return maxm.size();
    }
};