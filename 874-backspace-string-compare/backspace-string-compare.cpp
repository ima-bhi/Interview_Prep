class Solution {
public:
    string process(string s) {
        int i = 0;
        while (i < s.length()) {
            if (s[i] != '#') {
                i++;
            } else {
                if (i == 0) {
                    s.erase(0, 1);
                } else {
                    s.erase(i - 1, 2);
                    i--;
                }
            }
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        if (process(s) == process(t)) {
            return true;
        } else {
            return false;
        }
    }
};