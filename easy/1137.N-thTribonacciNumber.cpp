class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        int n0 = 0, n1 = 1, n2 = 1, ans;
        for(int i = 3; i <= n; ++i){
            ans = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = ans;
        }
        return ans;
    }
};