class Solution {
    int sumOfDigit(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(sumOfDigit(nums[i])==i){
                ans=i;
                break;
            }
            else{
                ans=-1;
            }
        }
        if(ans==-1){
            return -1;
        }
        else{
            return ans;
        }
    }
};