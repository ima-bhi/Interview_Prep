class Solution {
public:
    bool isPalindrome(string s) {
        // intialize left and right pointer
        int left = 0, right = s.length() - 1;
        while (left < right) {
            // skip left and right if num is not alphabet or numer
            if (!isalnum(s[left]))
                left++;
            else if (!isalnum(s[right]))
                right--;
            // if both are not same retuen false
            else if (tolower(s[left]) != tolower(s[right]))
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};