class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int prev = 2;
        int prevPrev = 1;
        for(int i = 3; i < n; ++i){
            int temp = prev;
            prev = temp + prevPrev;
            prevPrev = temp;
        }
        return prev + prevPrev;
    }
};