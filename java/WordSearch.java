class Solution {
    private boolean wordSearch(char[][] board, int i, int j, String word, int idx) {
        if(idx == word.length() - 1) return true;
        boolean res = false;
        
        board[i][j] -= 65;
        
        if(i > 0 && board[i-1][j] == word.charAt(idx+1) && wordSearch(board, i - 1, j, word, idx + 1)) return true;
        
        if(j > 0 && board[i][j-1] == word.charAt(idx+1) && wordSearch(board, i, j-1, word, idx + 1)) return true;
        
        if(i < (board.length-1) && board[i+1][j] == word.charAt(idx+1) && wordSearch(board, i+1, j, word, idx + 1)) return true;
        
        if(j < (board[0].length-1) && board[i][j+1] == word.charAt(idx+1) && wordSearch(board, i, j+1, word, idx + 1)) return true;
                      
                
        board[i][j] += 65;
        return res;      
        
    }
    
    
 
    public boolean exist(char[][] board, String word) {
        int row = board.length, col = board[0].length;
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word.charAt(0) && wordSearch(board, i, j, word, 0)) return true;
            }
        return false;   
    }
}
