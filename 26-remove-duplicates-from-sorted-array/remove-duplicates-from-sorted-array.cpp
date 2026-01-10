class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1,d=nums[0];
        for(int i=1;i<n;i++){
            if(d !=nums[i]){
                //means element is different
                nums[k++]=nums[i];
                d=nums[i];
            }
        }
        return k;
    }
};