class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        vector<int> ans;
        st.insert(nums.begin(),nums.end());
        int mn=*st.begin();
        int mx=*st.rbegin();
        for(int i=mn+1;i<mx;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};