#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int solution(vector<int> &A, vector<int> &B) {
    if(A.size() > 6*B.size() || B.size() > 6*A.size()) return -1;
    int sA = accumulate(A.begin(), A.end(), 0);
    int sB = accumulate(B.begin(), B.end(), 0);
    if(sA == sB) return 0;
    if(sA > sB){
        swap(sA, sB);
        swap(A, B);
        // make sure a < b
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end(), greater<int>());
    
    int count = 0;
    int num = 0;
    int dif = sB - sA;

    while(num < dif){
        int iA = A[0];
        int iB = abs(B[0]);
        int dA = 6 - iA; int dB = iB - 1;
        if(iA == 6 && iB == 1) return -1;
        count++;

        num += (max(dA, dB));
        if(dA > dB){
            A.erase(A.begin());
            A.push_back(6);
        else{
            B.pop_back();
            B.insert(B.begin(), -1);
        }
    }
    return count;
}
int main(){
    return 0;
}