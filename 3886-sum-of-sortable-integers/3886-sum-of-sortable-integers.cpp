

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

       
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;
            int prev_max = INT_MIN;

            for (int i = 0; i < n; i += k) {
                int drop_count = 0;
                int min_val = nums[i];
                int max_val = nums[i];

                
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k]; 

                    if (curr > next) {
                        drop_count++;
                    }
                    min_val = std::min(min_val, curr);
                    max_val = std::max(max_val, curr);
                }

             
                if (drop_count > 1) {
                    valid = false;
                    break;
                }

               
                if (min_val < prev_max) {
                    valid = false;
                    break;
                }

                prev_max = max_val;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
