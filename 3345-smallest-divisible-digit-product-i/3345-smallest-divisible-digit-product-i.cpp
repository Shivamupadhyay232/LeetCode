class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        for(int i=n;i<=n+9;i++){
        int temp=i;
        int prd=1;
            while(temp!=0){
                prd*=temp%10;
                temp/=10;
            }
            if(prd%t==0){
                return i;
            }
        }
        return -1;
    }
};