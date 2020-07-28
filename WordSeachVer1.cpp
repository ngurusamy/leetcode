class Solution {
    bool wordSearch(vector<vector<char>>& board, int i, int j, string & word, int idx, vector<vector<int>>  & visited) {
               if(idx == word.length() - 1) return true;
        bool res = false;
        
        visited[i][j] = 1;
        
        if(i > 0 && visited[i-1][j] == 0 && board[i-1][j] == word[idx+1] && wordSearch(board, i - 1, j, word, idx + 1, visited)) return true;
        
        if(j > 0 && visited[i][j-1] == 0 && board[i][j-1] == word[idx+1] && wordSearch(board, i, j-1, word, idx + 1, visited)) return true;
        
        if(i < (board.size()-1) && visited[i+1][j] == 0 && board[i+1][j] == word[idx+1] && wordSearch(board, i+1, j, word, idx + 1, visited)) return true;
        
        if(j < (board[0].size()-1) && visited[i][j+1] == 0 && board[i][j+1] == word[idx+1] && wordSearch(board, i, j+1, word, idx + 1, visited)) return true;
                      
                
        visited[i][j] = 0;
        return res;      
        
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> visited (row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0] && wordSearch(board, i, j, word, 0, visited)) return true;
            }
        return false;
    }
};
