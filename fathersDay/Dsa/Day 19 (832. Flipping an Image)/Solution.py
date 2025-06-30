class Solution:
    def flipAndInvertImage(self, image: list[list[int]]) -> list[list[int]]:
        for row in image:
            # Reverse the row and invert the values
            row.reverse()
            for i in range(len(row)):
                print(f"Before inversion: row[{i}] = {row[i]}")
                row[i] = 1 - row[i]
                
        return image
solution=Solution()
image = [[1,1,0],[1,0,1],[0,0,0]]
print(solution.flipAndInvertImage(image))  # Output: [[1,0,0],[0,1,0],[1,1,1]]