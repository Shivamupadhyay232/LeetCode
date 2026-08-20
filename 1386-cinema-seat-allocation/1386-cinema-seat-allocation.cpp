class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,set<int>> mp;
        for(auto seat:reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }
        int ans=2*n;
        for(auto row:mp){
            set<int> st=row.second;
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int i=2;i<=5;i++){
                if(st.find(i)!=st.end()){
                    left=false;
                    break;
                }
            }
            for(int i=4;i<=7;i++){
                if(st.find(i)!=st.end()){
                    middle=false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(st.find(i)!=st.end()){
                    right=false;
                    break;
                }
            }
            if(left && right){
                continue;
            }
            else if(left || right || middle){
                ans--;
            }
            else{
                ans-=2;
            }
        }
        return ans;
    }
};