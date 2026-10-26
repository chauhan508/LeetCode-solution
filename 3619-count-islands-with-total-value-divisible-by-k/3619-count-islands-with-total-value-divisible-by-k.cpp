

class Solution {
private:
    int m, n;

    long long dfs(std::vector<std::vector<int>>& grid, int r, int c) {
      
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }

       
        long long island_sum = grid[r][c];
        grid[r][c] = 0; 

        // Explore all 4 directions
        island_sum += dfs(grid, r + 1, c);
        island_sum += dfs(grid, r - 1, c);
        island_sum += dfs(grid, r, c + 1);
        island_sum += dfs(grid, r, c - 1);

        return island_sum;
    }

public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        int count = 0;

      
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                   
                    long long total_value = dfs(grid, i, j);
                    if (total_value % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
