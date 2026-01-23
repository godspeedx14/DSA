```cpp
/*
 * Core Idea:
 * Validates a Sudoku board by iterating through each cell and ensuring that
 * no digit (1-9) is repeated within its respective row, column, or 3x3 subgrid.
 * Three hash maps are used to efficiently track seen digits for rows, columns, and 3x3 blocks.
 *
 * Time Complexity:
 * O(1) - The algorithm processes each of the 81 cells once. Hash map operations (insert, lookup)
 * are O(1) on average. Since the board size is fixed (9x9), the total operations are constant.
 *
 * Space Complexity:
 * O(1) - Three hash maps are used to store seen digits for rows, columns, and 3x3 blocks.
 * Each map will store at most 9 entries (for rows/cols/blocks), and each inner map will
 * store at most 9 distinct digits. As the board size is fixed, the memory usage is constant.
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_map<char,bool>>r;
        unordered_map<int,unordered_map<char,bool>>c;
        unordered_map<int,unordered_map<char,bool>>b;
        
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
            {
                if (board[i][j]=='.')continue;
                if (r[i].count(board[i][j]) || c[j].count(board[i][j]) || b[(i/3)*3+j/3].count(board[i][j])) return false;

                r[i][board[i][j]]=true;
                c[j][board[i][j]]=true;
                b[(i/3)*3+j/3][board[i][j]]=true;

            }
        return true;
    }
};
```