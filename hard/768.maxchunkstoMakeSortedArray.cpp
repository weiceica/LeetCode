#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        int diff = 0;
        int count = 0;
        for(int i = 0; i < arr.size(); ++i){
            diff += arr[i] - sortedArr[i];
            if(diff == 0){
                count++;
                diff = 0;
            }
        }
        return count;
    }
};