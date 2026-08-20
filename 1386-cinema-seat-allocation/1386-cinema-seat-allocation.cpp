class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for(auto &seat:reservedSeats){
            mp[seat[0]].push_back(seat[1]);
        }
        int ans=2*n;
        for(auto &[row,seats]:mp){
            bool left=true,middle=true,right=true;
            for(int x:seats){
                if(x>=2 && x<=5) left=false;
                if(x>=4 && x<=7) middle=false;
                if(x>=6 && x<=9) right=false;
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