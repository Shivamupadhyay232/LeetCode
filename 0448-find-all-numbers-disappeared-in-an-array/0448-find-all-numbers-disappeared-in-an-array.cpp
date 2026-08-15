class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        st.insert(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};