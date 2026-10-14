#include <string>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        // If the sum is greater than the maximum possible sum with 'num' digits, it's impossible.
        if (sum > 9 * num) {
            return "";
        }
        
        int num_9s = sum / 9;
        int rem = sum % 9;
        int num_0s = num - num_9s - (rem > 0 ? 1 : 0);
        
        std::string result = "";
        result.append(num_9s, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(num_0s, '0');
        
        return result;
    }
};
