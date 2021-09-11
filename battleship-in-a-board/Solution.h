// LeetCode 419. Battleships in a Board
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int cnt = 0;
        
        numRow = board.size();        
        if (!numRow) {
            return cnt; 
        }
        
        numCol = board[0].size();
        
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (board[i][j] == 'X') {
                    cnt++;
                    _resetBoard(board, i, j); 
                }
            }
        }        
        
        return cnt; 
        
    }
    
private:
    int numRow;
    int numCol; 
    
    void _resetBoard(vector<vector<char>>& board, int i, int j) {
        
        if (i < 0 || i >= numRow || j < 0 || j >= numCol || board[i][j] == '.') {
            // base case
            return; 
        }
        
        board[i][j] = '.';
        
        if (i + 1 < numRow && board[i + 1][j] == 'X') {
            // vertical search
            _resetBoard(board, i + 1, j);    
        }        
        else {
            // horizontal search
            _resetBoard(board, i, j + 1);    
        }        
        
    }
};