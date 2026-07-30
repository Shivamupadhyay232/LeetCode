class Solution {
public:
    int fibn(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return fibn(n-1)+fibn(n-2);
    }
    int fib(int n) {
        int ans=fibn(n);
        return ans;
    }
};