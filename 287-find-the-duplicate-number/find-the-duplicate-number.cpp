class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //initalize to pointer
        int slow=nums[0];
        int fast=nums[0];
        //find cycle
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);

        // find starting point 
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};