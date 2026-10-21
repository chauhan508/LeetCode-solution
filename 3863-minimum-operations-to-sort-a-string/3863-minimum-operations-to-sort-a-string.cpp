class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
      
        if (is_sorted(s.begin(), s.end())) return 0;
        
      
        if (n == 2) return -1;
        
        char min_char = 'z', max_char = 'a';
        for (char c : s) {
            min_char = min(min_char, c);
            max_char = max(max_char, c);
        }
        
     
        if (s[0] == min_char || s[n - 1] == max_char) return 1;
        
      
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char || s[i] == max_char) return 2;
        }
        
      
        return 3;
    }
};
