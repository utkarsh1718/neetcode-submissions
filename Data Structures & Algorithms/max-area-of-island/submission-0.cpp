class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        int area = 1;
        
        // 4 directions
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    area++;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = bfs(i, j, vis, grid);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
