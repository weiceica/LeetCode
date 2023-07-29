#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> memo(citations.size() + 1, 0);
        for(int i = 0; i < citations.size(); ++i){
            int temp = citations[i];
            if(temp > citations.size()) temp = citations.size();
            memo[temp]++;
        }
        int count = 0;
        for(int i = memo.size() - 1; i >= 0; --i){
            count += memo[i];
            if(count >= i) return i;
        }
        return 0;
    }
};