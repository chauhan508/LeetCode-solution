

class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, long long budget) {
        int n = items.size();
        vector<int> cntFactor(n + 1, 0);
        long long minPrice = LLONG_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];
            cntFactor[factor]++;
            minPrice = min(minPrice, price);
        }

        vector<int> cntMulti(n + 1, 0);
        map<long long, long long> priceToBonus;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (price >= 2 * minPrice) {
                continue;
            }

            if (cntMulti[factor] == 0) {
                int totalMulti = 0;
                for (int mult = factor; mult <= n; mult += factor) {
                    totalMulti += cntFactor[mult];
                }
                cntMulti[factor] = totalMulti;
            }

            long long freeTargets = cntMulti[factor] - 1;
            if (freeTargets > 0) {
                priceToBonus[price] += freeTargets;
            }
        }

        long long ans = 0;
        for (const auto& [price, available] : priceToBonus) {
            if (budget < price) {
                break;
            }
            long long take = min(available, budget / price);
            budget -= take * price;
            ans += take * 2;
        }

        ans += budget / minPrice;
        return ans;
    }
};
