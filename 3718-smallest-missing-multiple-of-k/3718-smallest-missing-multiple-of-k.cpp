class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mul=k;
        while(st.find(mul)!=st.end()){
            mul+=k;
        }
        return mul;
    }
};