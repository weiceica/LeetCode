#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void magicalshit(vector<string>& retval, vector<string>& retmap, string& digits, string& curString, int pos){
        if(digits.length() == curString.length()){
            retval.push_back(curString);
            return;
        }
        int idx = digits[pos] - '0';
        for(int i = 0; i < retmap[idx].length(); ++i){
            curString += retmap[idx][i];
            magicalshit(retval, retmap, digits, curString, pos+1);
            curString.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> retmap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> retval;
        string curString = "";
        if(digits == "") return retval;
        magicalshit(retval, retmap, digits, curString, 0);
        return retval;
    }
};