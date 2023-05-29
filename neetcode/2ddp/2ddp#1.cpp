class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int R = m - 1;
        double c = 1;
        for(int i = 1; i <= R; ++i)
            c = c * (N - R + i) / i;
        return (int)c;
    }
    // NCR lmaooo lmaooo
    // ex 3x3
    /*
    
    - - - -
    - - - -
    - - - -
    - - - -

    4 + 4 = 8
    8 - 2 = 6

    r = 3

    nCr = (n!) / (n-r)! r!
    
    
    */
};