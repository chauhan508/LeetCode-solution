



class Solution {
public:
    int minMoves(vector<string>& classroom, int maxEnergy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        map<pair<int, int>, int> litterMap;
        int litterCount = 0;
        
     
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterMap[{i, j}] = litterCount++;
                }
            }
        }
        
        int targetMask = (1 << litterCount) - 1;
        
       
        vector<vector<vector<int>>> maxEnergyAtState(m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1)));
        
      
        queue<tuple<int, int, int, int>> q;
        
        q.push({startX, startY, 0, maxEnergy});
        maxEnergyAtState[startX][startY][0] = maxEnergy;
        
        int moves = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            int currentLevelSize = q.size();
            
            for (int k = 0; k < currentLevelSize; ++k) {
                auto [x, y, mask, e] = q.front();
                q.pop();
                
              
                if (mask == targetMask) {
                    return moves;
                }
                
              
                if (e < maxEnergyAtState[x][y][mask]) {
                    continue;
                }
                
              
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d][0];
                    int ny = y + dirs[d][1];
                    
           
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') {
                        continue;
                    }
                    
                
                    int nextEnergy = e - 1;
                    int nextMask = mask;
              
                    if (nextEnergy < 0) {
                        continue;
                    }
                    
                
                    if (classroom[nx][ny] == 'R') {
                        nextEnergy = maxEnergy;
                    } else if (classroom[nx][ny] == 'L') {
                        int idx = litterMap[{nx, ny}];
                        nextMask |= (1 << idx);
                    }
                    
                 
                    if (nextEnergy > maxEnergyAtState[nx][ny][nextMask]) {
                        maxEnergyAtState[nx][ny][nextMask] = nextEnergy;
                        q.push({nx, ny, nextMask, nextEnergy});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};
