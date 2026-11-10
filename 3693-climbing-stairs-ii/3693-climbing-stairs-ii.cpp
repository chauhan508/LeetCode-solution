
class Solution {
public:
    int climbStairs(int n, std::vector<int>& costs) {
        
        std::vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            long long current_cost = costs[i - 1];
            
            for (int j = std::max(0, i - 3); j < i; ++j) {
                long long jump_dist = i - j;
                long long cost_from_j = dp[j] + current_cost + (jump_dist * jump_dist);
                dp[i] = std::min(dp[i], cost_from_j);
            }
        }
        
        return dp[n];
    }
};
