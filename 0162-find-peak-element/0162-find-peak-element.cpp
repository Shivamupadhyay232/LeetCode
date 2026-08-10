class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid;
        if(n==1){
            return 0;
        }
        while(s<e){
            mid=s+((e-s)/2);
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                s=mid+1;
            }
            else if(mid==n-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                e=mid-1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(s==e){
            return s;
        }
        return -1;
    }
};