
class Solution {
public:
    int uniquePaths(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        const int MOD = 1e9 + 7;

   
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

       
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
              
                if (grid[i][j] == 1 || dp[i][j] == 0) continue;

                int currentPaths = dp[i][j];

                // --- OPTION 1: Move Right from (i, j) ---
                int ni = i, nj = j + 1;
                int dir = 0; // 0 = Right, 1 = Down
                while (ni < m && nj < n && grid[ni][nj] == 1) {
                    if (dir == 0) {
                        ni++;
                        dir = 1;
                    } else {
                        nj++; 
                        dir = 0;
                    }
                }
               
                if (ni < m && nj < n) {
                    dp[ni][nj] = (dp[ni][nj] + currentPaths) % MOD;
                }

                // --- OPTION 2: Move Down from (i, j) ---
                ni = i + 1; nj = j;
                dir = 1; // 0 = Right, 1 = Down
                while (ni < m && nj < n && grid[ni][nj] == 1) {
                    if (dir == 1) {
                        nj++; // Reflected Right
                        dir = 0;
                    } else {
                        ni++; // Reflected Down
                        dir = 1;
                    }
                }
                
                if (ni < m && nj < n) {
                    dp[ni][nj] = (dp[ni][nj] + currentPaths) % MOD;
                }
            }
        }

       
        return dp[m - 1][n - 1];
    }
};
