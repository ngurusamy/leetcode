class Solution {
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int & perimeter) {
        grid[i][j] = 2;
        if(i == 0 || grid[i - 1][j] == 0) perimeter++;
        if(i == grid.size() - 1 || grid[i + 1][j] == 0) perimeter++;
        if(j == 0 || grid[i][j - 1] == 0) perimeter++;
        if(j == grid[0].size() - 1 || grid[i][j + 1] == 0) perimeter++;
        
        if(i > 0 && grid[i - 1][j] == 1) dfs(grid, i - 1, j, perimeter);
        if(i < grid.size() - 1 && grid[i + 1][j] == 1) dfs(grid, i + 1, j, perimeter);
        if(j > 0 && grid[i][j - 1] == 1) dfs(grid, i, j - 1, perimeter);
        if(j < grid[0].size() - 1 && grid[i][j + 1] == 1) dfs(grid, i, j + 1, perimeter);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
    
        int perimeter = 0;
        

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, perimeter);
                }
            }
        }
        return perimeter;
    }
};
