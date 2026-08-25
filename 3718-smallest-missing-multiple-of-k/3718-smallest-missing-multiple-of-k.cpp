

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
       
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
     
        int multiple = k;
        
       
        while (num_set.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
    }
};
