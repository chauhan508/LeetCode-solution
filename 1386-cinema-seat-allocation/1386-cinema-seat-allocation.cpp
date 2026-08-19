

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        
        std::unordered_map<int, int> row_map;
        for (const auto& seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            row_map[r] |= (1 << (c - 1));
        }

     
        long long ans = (static_cast<long long>(n) - row_map.size()) * 2;

       
        int left_mask  = 0b0111100000; 
        int right_mask = 0b0000011110; 
        int mid_mask   = 0b0001111000; 

        for (const auto& [row, mask] : row_map) {
            bool allocated = false;

         
            if ((mask & left_mask) == 0) {
                ans += 1;
                allocated = true;
            }
          
            if ((mask & right_mask) == 0) {
                ans += 1;
                allocated = true;
            }
          
            if (!allocated && (mask & mid_mask) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};
