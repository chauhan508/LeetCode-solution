
class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        
        int zero_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero_idx = i;
                break;
            }
        }

        
        auto isValidCyclicOrder = [&](int step) -> bool {
            for (int i = 1; i < n; ++i) {
               
                int prev = (zero_idx + (i - 1) * step % n + n) % n;
                int curr = (zero_idx + i * step % n + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int min_ops = 1e9; 

        
        if (isValidCyclicOrder(1)) {
            
            min_ops = std::min(min_ops, zero_idx);
            
            min_ops = std::min(min_ops, n - zero_idx + 2);
        }

        
        if (isValidCyclicOrder(-1)) {
           
            min_ops = std::min(min_ops, n - zero_idx);
         
            min_ops = std::min(min_ops, zero_idx + 2);
        }

        return (min_ops == 1e9) ? -1 : min_ops;
    }
};
