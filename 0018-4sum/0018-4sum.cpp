class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_map<long long,int>mp;
                for(int k=j+1;k<n;k++){ 
                    long long sum=1LL*nums[i]+nums[j]+nums[k];
                    long long rem=target-sum;
                    if(mp.find(rem)!=mp.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)rem};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    mp[nums[k]]++;
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};