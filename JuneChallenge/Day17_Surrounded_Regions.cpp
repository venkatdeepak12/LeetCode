/*

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

//Code:

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        for(int c = 0; c < board[0].size(); c++){
            if(board[0][c] == 'O') fillWithU(board, 0, c); //top row 
            if(board[board.size()-1][c] == 'O') fillWithU(board, board.size()-1, c); //bottom row
        }
        for(int r = 0; r < board.size(); r++){
            if(board[r][0] == 'O') fillWithU(board, r, 0); //left column
            if(board[r][board[0].size()-1] == 'O') fillWithU(board, r, board[0].size()-1); //right column
        }
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == 'U') board[r][c] = 'O';
            }
        }

    }
    void fillWithU(vector<vector<char>> &board, int r, int c){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'U') return;
        board[r][c] = 'U';
        fillWithU(board, r+1, c);
        fillWithU(board, r, c+1);
        fillWithU(board, r-1, c);
        fillWithU(board, r, c-1);
    }
};
