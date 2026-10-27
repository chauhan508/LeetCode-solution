

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
       
        std::vector<std::string> grid(m, std::string(n, '#'));
        
      
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
  
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};
