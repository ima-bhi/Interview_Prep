class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            //validate condition and push the value 
            if(nums[i]!=val){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};