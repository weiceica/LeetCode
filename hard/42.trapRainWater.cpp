#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int lmx = height[0];
        int rmx = height.back();
        int l = 1; int r = height.size() - 2;
        int water = 0;
        while(l <= r){
            if(lmx > rmx){
                if(height[r] < rmx) water += rmx - height[r];
                else rmx = height[r];
                r--;
            }else{
                if(height[l] < lmx) water += lmx - height[l];
                else lmx = height[l];
                l++;
            }
        }
        return water;
    }
};