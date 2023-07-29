#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        int max = prices[0];
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < min) min = prices[i];
            if(prices[i] > max){
                profit += prices[i] - max;
                max = prices[i];
            }
            else{
                min = prices[i];
                max = prices[i];
            }
        }
        return profit;
    }
};