import java.util.HashSet;

public class solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> seen = new HashSet<>();
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                char current = board[i][j];
                if (current != '.' && (current < '1' || current > '9')) {
                    return false; // Invalid character found
                }
                
                if (current != '.') {
                    String rowKey = "row" + i + current;
                    String colKey = "col" + j + current;
                    String boxKey = "box" + (i / 3) + (j / 3) + current;

                    if (!seen.add(rowKey) || !seen.add(colKey) || !seen.add(boxKey)) {
                        return false; // Duplicate detected
                    }
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        solution sol = new solution();
        char[][] board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '2', '1', '9', '.', '.', '.'},
            {'.', '6', '.', '.', '.', '2', '8', '.', '.'},
            {'.', '.', '2', '4', '1', '9', '.', '8', '.'},
            {'.', '8', '7', '9', '5', '6', '.', '.', '.'}
        };
        System.out.println(sol.isValidSudoku(board)); // Output: true
    }
}