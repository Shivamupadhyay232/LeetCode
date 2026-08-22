class Solution {
public:
    bool checkDivisibility(int n) {
        int b=n;
        int sum=0;
        int prod=1;
        while(n!=0){
            int a=n%10;
            sum+=a;
            prod*=a;
            n/=10;
        }
        if(b%(sum+prod)==0){
            return true;
        }
        return false;
    }
};