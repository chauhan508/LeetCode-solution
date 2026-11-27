
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_price = INT_MAX;
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int factor = items[i][0];
            int price = items[i][1];
            min_price = min(min_price, price);

            
            int gain = 0;
            for (int j = 0; j < n; ++j) {
                if (items[j][0] % factor == 0) {
                    gain++;
                }
            }

            
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b] + (budget - b) / min_price);
        }

        return ans;
    }
};
