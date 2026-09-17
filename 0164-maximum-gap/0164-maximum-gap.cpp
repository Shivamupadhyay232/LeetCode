class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
        {
            return 0;
        }
        int maxV= *max_element(nums.begin(),nums.end());
        int minV= *min_element(nums.begin(),nums.end());
        if(maxV==minV)
        {
            return 0;
        }
        int range = maxV-minV;
        int size = (range+n-2)/(n-1);
        int bucketCount = (range/size)+1;
        vector<int> bucketMin(bucketCount , INT_MAX);
        vector<int> bucketMax(bucketCount , INT_MIN);
        vector<bool> used(bucketCount , false);
        for(int x:nums)
        {
            int idx=(x-minV)/size;
            bucketMin[idx]=min(bucketMin[idx],x);
            bucketMax[idx]=max(bucketMax[idx],x);
            used[idx] = true;
        }
        int ans=0;
        int prev = minV;
        for(int i=0; i<bucketCount; i++)
        {
            if(!used[i])
            {
                continue;
            }
            ans=max(ans,bucketMin[i]-prev);
            prev=bucketMax[i];
        }
        return ans;
    }
};