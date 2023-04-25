#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(top-0 != s[i]-2 && top-0 != s[i]-1) return false;
            }
        }
        return st.empty();
    }
};