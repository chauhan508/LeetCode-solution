class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            digitSum += digit;
            digitProduct *= digit;
        }
        
        return n % (digitSum + digitProduct) == 0;
    }
};
