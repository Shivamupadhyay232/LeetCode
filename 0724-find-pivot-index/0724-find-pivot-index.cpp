class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totSum=0;
        int leftSum=0;
        int rightSum=0;
        for(int num:nums){
            totSum+=num;
        }
        for(int i=0;i<nums.size();i++){
            rightSum=totSum-leftSum-nums[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};