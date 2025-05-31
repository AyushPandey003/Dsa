from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        VALID_DIGITS = set("123456789")
        seen_rows = [set() for _ in range(9)]
        seen_cols = [set() for _ in range(9)]
        seen_grids = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                cell = board[i][j]
                if cell == ".":
                    continue

                if cell not in VALID_DIGITS:
                    return False 

                grid_index = (i // 3) * 3 + (j // 3)
                
                if (cell in seen_rows[i] or 
                    cell in seen_cols[j] or 
                    cell in seen_grids[grid_index]):
                    return False  

                seen_rows[i].add(cell)
                seen_cols[j].add(cell)
                seen_grids[grid_index].add(cell)

        return True
board=[
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
k=Solution()
print(k.isValidSudoku(board))