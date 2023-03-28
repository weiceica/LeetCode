from typing import List
import collections
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        box = collections.defaultdict(set)
        for i in range(9):
            for j in range(9):
                ele = board[i][j]
                if(ele != '.'):
                    if(ele in rows[i] or ele in cols[j] or ele in box[(i//3,j//3)]):
                        return False
                    else:
                        rows[i].add(ele)
                        cols[j].add(ele)
                        box[(i//3,j//3)].add(ele)
        return True