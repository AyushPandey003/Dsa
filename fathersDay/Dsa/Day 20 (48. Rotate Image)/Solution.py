class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        matrix[:] = [list(row) for row in zip(*matrix[::-1])]
        return matrix
                
solution=Solution( )
matrix = [[1,2,3],[4,5,6],[7,8,9]]
solution.rotate(matrix)
print(matrix)  # Output: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]