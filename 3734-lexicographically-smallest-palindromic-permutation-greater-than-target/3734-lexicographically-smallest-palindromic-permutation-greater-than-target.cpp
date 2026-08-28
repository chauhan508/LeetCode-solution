

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = '#';
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = (char)('a' + i);
            }
            count[i] /= 2;
        }

        if (odd_count > 1) return "";

        int half_len = n / 2;
        string left_half = "";
        
        if (dfs(0, half_len, count, mid_char, target, false, left_half)) {
            string right_half = left_half;
            reverse(right_half.begin(), right_half.end());
            if (mid_char != '#') {
                return left_half + mid_char + right_half;
            }
            return left_half + right_half;
        }

        return "";
    }

private:
    bool dfs(int idx, int half_len, vector<int>& count, char mid_char, 
             const string& target, bool is_greater, string& current_left) {
        
        if (idx == half_len) {
          
            string right = current_left;
            reverse(right.begin(), right.end());
            string full_pal = current_left;
            if (mid_char != '#') full_pal += mid_char;
            full_pal += right;
            
            return full_pal > target;
        }

        
        char start_char = is_greater ? 'a' : target[idx];

        for (char c = start_char; c <= 'z'; ++c) {
            int char_idx = c - 'a';
            if (count[char_idx] > 0) {
                count[char_idx]--;
                current_left.push_back(c);

                bool next_greater = is_greater || (c > target[idx]);
                if (dfs(idx + 1, half_len, count, mid_char, target, next_greater, current_left)) {
                    return true;
                }

               
                current_left.pop_back();
                count[char_idx]++;
            }
        }
        return false;
    }
};
