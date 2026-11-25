
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long base1 = 100003, mod1 = 1000000007;
        const long long base2 = 100019, mod2 = 1000000009;

        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
            // Add offset to handle 0 or negative values safely if constraints allow
            long long val = (long long)nums[i] + 1000000001LL;
            pref1[i + 1] = (pref1[i] * base1 + (val % mod1)) % mod1;
            pref2[i + 1] = (pref2[i] * base2 + (val % mod2)) % mod2;
        }

        auto getHash = [&](int l, int r) -> uint64_t {
            int len = r - l;
            long long h1 = (pref1[r] - (pref1[l] * pow1[len]) % mod1 + mod1) % mod1;
            long long h2 = (pref2[r] - (pref2[l] * pow2[len]) % mod2 + mod2) % mod2;
            return (static_cast<uint64_t>(h1) << 32) | static_cast<uint64_t>(h2);
        };

        auto hasUnique = [&](int len) -> bool {
            unordered_map<uint64_t, int> counts;
            counts.reserve(n - len + 1);
            for (int i = 0; i <= n - len; ++i) {
                counts[getHash(i, i + len)]++;
            }
            for (const auto& [hashVal, cnt] : counts) {
                if (cnt == 1) return true;
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
