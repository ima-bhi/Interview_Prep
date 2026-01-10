class Solution {
public:
    void reverse(vector<int>& num, int low, int high) {
        while (low < high) {
            swap(num[low], num[high]);
            low++;
            high--;
        }
    }
    // main function to rotate
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Example :
        // arr = [1,2,3,4,5,6,7]
        //  rev1 - [4,3,2,1] , rev2 - [7,6,5]
        //  final reverse : [5,6,7,1,2,3,4]
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};