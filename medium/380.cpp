#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
private:
unordered_map<int, int> umap;
vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(umap.count(val) != 0) return false;
        umap[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(umap.count(val) == 0) return false;
        int cind = umap[val];
        int lv = v.back();
        v[cind] = lv;
        v.pop_back();
        umap[lv] = cind;
        umap.erase(val);
        return true;
    }
    
    int getRandom() {
        int r = rand() % v.size();
        return  v[r];
    }
};