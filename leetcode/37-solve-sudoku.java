// https://leetcode.com/problems/sudoku-solver/
class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }

    private boolean solve(char[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, r, c, d)) {
                            board[r][c] = d;

                            if (solve(board)) return true; //recurse

                            board[r][c] = '.'; //backtrack
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    } 

    private boolean isValid(char[][] board, int row, int col, char digit) {
        // check row and col
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit) return false;
            if (board[i][col] == digit) return false;
        }

        // check 3x3 box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == digit) return false;
            }
        }

        return true;
    }
}