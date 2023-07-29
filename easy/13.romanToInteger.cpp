#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int count = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i] == 'V') count += 5;
            else if(s[i] == 'L') count += 50;
            else if(s[i] == 'D') count += 500;
            else if(s[i] == 'M') count += 1000;
            else if(s[i] == 'I'){
                if(i != s.size() - 1){
                    if(s[i+1] == 'V'){
                        i++;
                        count += 4;
                    }
                    else if(s[i+1] == 'X'){
                        i++;
                        count += 9;
                    }
                    else count += 1;
                }
                else count += 1;
            }
            else if(s[i] == 'X'){
                if(i != s.size() - 1){
                    if(s[i+1] == 'L'){
                        i++;
                        count += 40;
                    }
                    else if(s[i+1] == 'C'){
                        i++;
                        count += 90;
                    }
                    else count += 10;
                }
                else count += 10;
            }
            else if(s[i] == 'C'){
                if(i != s.size() - 1){
                    if(s[i+1] == 'D'){
                        i++;
                        count += 400;
                    }
                    else if(s[i+1] == 'M'){
                        i++;
                        count += 900;
                    }
                    else count += 100;
                }
                else count += 100;
            }
            ++i;
            cout << count << endl;
        }
        return count;
    }
};