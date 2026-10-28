
class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        std::vector<std::bitset<1024>> dp(n);
        
        dp[0].set(grid[0][0]);
        
   
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int x = 0; x < 1024; ++x) {
                if (dp[j - 1].test(x)) {
                    dp[j].set(x ^ val);
                }
            }
        }
        
     
        for (int i = 1; i < m; ++i) {
           
            std::bitset<1024> next_col0;
            int val0 = grid[i][0];
            for (int x = 0; x < 1024; ++x) {
                if (dp[0].test(x)) {
                    next_col0.set(x ^ val0);
                }
            }
            dp[0] = next_col0;
            
           
            for (int j = 1; j < n; ++j) {
                std::bitset<1024> current_cell;
                std::bitset<1024> combined = dp[j] | dp[j - 1];
                
                int val = grid[i][j];
                for (int x = 0; x < 1024; ++x) {
                    if (combined.test(x)) {
                        current_cell.set(x ^ val);
                    }
                }
                dp[j] = current_cell;
            }
        }
        
       
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1].test(x)) {
                return x;
            }
        }
        
        return -1;
    }
};
