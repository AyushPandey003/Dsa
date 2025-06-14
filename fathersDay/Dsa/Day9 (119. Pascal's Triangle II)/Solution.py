class Solution:
    def PascalsTriangle(self, rowIndex: int) -> list[int]:
        if rowIndex < 0:
            return []
        if rowIndex == 0:
            return [1]
        
        triangle = [[1] * (i + 1) for i in range(rowIndex + 1)]
        
        for i in range(2, rowIndex + 1):
            for j in range(1, i):
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        
        return triangle[rowIndex]
    