

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        
       
        for (const int x : nums1) {
            if (x % 2 != 0) {
                min_odd = std::min(min_odd, x);
            } else {
                min_even = std::min(min_even, x);
            }
        }
        
       
        if (min_odd == INT_MAX) {
            return true;
        }
        
       
        if (min_even < min_odd) {
            return false;
        }
        
        return true;
    }
};
