class Solution {
public:
    bool hasEvenDigits(int num) {
        int digits = 0;
        if (num == 0)
            return false; // 0 has 1 digit (odd)
        num = abs(num);
        while (num > 0) {
            digits++;
            num /= 10;
        }
        return digits % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for (int i = 0; i < nums.size(); i++) {
            bool evenNum = hasEvenDigits(nums[i]);
            if (evenNum)
                even++;
        }
        return even;
    }
};