#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> memo(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i-1]) memo[i] = memo[i-1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; --i){
            if(ratings[i + 1] < ratings[i] && memo[i] <= memo[i+1])
                memo[i] = memo[i+1] + 1;
        }
        int count = 0;
        for(int i = 0; i < memo.size(); ++i) count += memo[i];
        return count;
    }
};