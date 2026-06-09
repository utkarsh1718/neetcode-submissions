class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds → contributes to perimeter
        if(row < 0 || col < 0 || row >= n || col >= m) return 1;

        // Water → contributes to perimeter
        if(grid[row][col] == 0) return 1;

        // Already visited → no contribution
        if(vis[row][col]) return 0;

        vis[row][col] = 1;

        int perimeter = 0;
        perimeter += dfs(row-1, col, grid, vis);
        perimeter += dfs(row+1, col, grid, vis);
        perimeter += dfs(row, col-1, grid, vis);
        perimeter += dfs(row, col+1, grid, vis);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return dfs(i, j, grid, vis); // only one island
                }
            }
        }
        return 0;
    }
};