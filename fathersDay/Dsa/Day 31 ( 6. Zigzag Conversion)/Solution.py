class Solution:
    def ZigZagConvert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        
        # Create a list of strings for each row
        rows = [''] * numRows
        current_row = 0
        going_down = False
        
        for char in s:
            rows[current_row] += char
            
            # Change direction if we hit the top or bottom row
            if current_row == 0:
                going_down = True
            elif current_row == numRows - 1:
                going_down = False
            
            # Move to the next row
            current_row += 1 if going_down else -1
        
        # Join all rows to get the final zigzag string
        return ''.join(rows)
# Example usage:
solution = Solution()
s = "PAYPALISHIRING"
numRows = 3
result = solution.ZigZagConvert(s, numRows)
print(result)  # Output: "PAHNAPLSIIGYIR"