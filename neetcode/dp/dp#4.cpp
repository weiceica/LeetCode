#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string subStr = "";
        int longestLength = 0;
        for(int i = 0; i < s.length(); ++i){
            int left = i, right = i;
            while(left > -1 && right < s.length() && s[left] == s[right]){
                if(right - left + 1 > longestLength){
                    longestLength = right - left + 1;
                    subStr = s.substr(left, right - left + 1);
                }
                left--; right++;
            }
            left = i, right = i + 1;
            while(left > -1 && right < s.length() && s[left] == s[right]){
                if(right - left + 1 > longestLength){
                    longestLength = right - left + 1;
                    subStr = s.substr(left, right - left + 1);
                }
                left--; right++;
            }
        }
        return subStr;
    }
};