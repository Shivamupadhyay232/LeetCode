class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        
        int totsum=0;
        for(int j=0;j<n;j++){
            totsum+=cardPoints[j];
        }

        if(k==n){
            return totsum;
        }
        int sum=0;
        int l=n-k;
        int mini=INT_MAX;
        int i=0;
        for(int j=i;j<n;j++){
            sum+=cardPoints[j];
            l--;
            while(l<=0){
                mini=min(mini,sum);
                sum-=cardPoints[i];
                i++;
                l++;
            }
        }
        return totsum-mini ;
    }
};