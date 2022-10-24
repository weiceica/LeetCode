#include <vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int> memo;
        memo.resize(n + 1);
        if(n == 0) return 0;
        if(n == 1) return 1;
        memo[0] = 0; memo[1] = 1;
        for(size_t i = 2; i < memo.size(); ++i){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo.back();
    }
};