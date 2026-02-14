class Solution {
public:
    bool isValid(string s) {
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            char cr = s[r];
            // '(,{,[ ' --- l++
            // else r co pare with l-- means s[l--]
            if (cr == '(' || cr == '{' || cr == '[')
                s[l++] = cr;
            else {
                if (l == 0)
                    return false;
                if (cr == ')' && s[--l] != '(')
                    return false;
                else if (cr == '}' && s[--l] != '{')
                    return false;
                else if (cr == ']' && s[--l] != '[')
                    return false;
            }
            r++;
        }
        return l == 0;
    }
};