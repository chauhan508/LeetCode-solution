

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
      
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        
        long long option1 = n1 * c1 + n2 * c2;

       
        long long option2 = std::max(n1, n2) * cb;

       
        long long mn = std::min(n1, n2);
        long long rem1 = n1 - mn;
        long long rem2 = n2 - mn;

        long long option3 = (mn * cb) 
                            + (rem1 * std::min(c1, cb)) 
                            + (rem2 * std::min(c2, cb));

        
        return std::min({option1, option2, option3});
    }
};
