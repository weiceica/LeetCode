#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void magicalshit(vector<vector<string>>& retval, vector<string>& curset, string&s, int pos){
        if(pos == s.length()){
            retval.push_back(curset);
            return;
        }
        string str = "";
        for(int i = pos; i < s.length(); ++i){
            str += s[i];
            if(isPalindrome(s, pos, i)){
                curset.push_back(str);
                magicalshit(retval, curset, s, i+1);
                curset.pop_back();
            }
        }   
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> retval;
        vector<string> curset;
        magicalshit(retval, curset, s, 0);
        return retval; 
    }
};