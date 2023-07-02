#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool magicalshit(vector<vector<char>>& board, string word, int pos, int x, int y){
        if(pos == word.length()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[pos]) return false;
        char c = board[x][y];
        board[x][y] = '*';
        bool mag = magicalshit(board, word, pos+1, x-1, y) ||
                   magicalshit(board, word, pos+1, x+1, y) ||
                   magicalshit(board, word, pos+1, x, y-1) ||
                   magicalshit(board, word, pos+1, x, y+1);
        board[x][y] = c;
        return mag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0] && magicalshit(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};