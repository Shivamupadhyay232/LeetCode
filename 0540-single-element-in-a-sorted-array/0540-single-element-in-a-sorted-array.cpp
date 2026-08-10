class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid;
        while(s<e){
            mid=s+((e-s)/2);
            if(mid==0){
                if(nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
            }
            else if(mid==n-1){
                if(nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }
            }
            else if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    s=mid+1;
                }
                else{
                    e=mid;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    s=mid+1;
                }
                else{
                    e=mid;
                }
            }
        }
        if(s==e){
            return nums[s];
        }
        return -1;
    }
};