class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            set<int> st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(auto it:st){
                mp[it]++;
            }
        }
        int maxi=-1;
        for(auto it:mp){
            if(it.second==1){
                maxi=max(maxi,it.first);
            }
        }
        return maxi;
    }
};