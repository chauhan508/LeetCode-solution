

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int n = nums.size();
        
        bool is_sorted = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted) return 0;
        
      
        int max_val = n - 1;
        long long mask = 1;
        while (mask <= max_val) {
            mask <<= 1;
        }
        int k = mask - 1;
        
      
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                k &= nums[i];
            }
        }
        
        return k;
    }
};
