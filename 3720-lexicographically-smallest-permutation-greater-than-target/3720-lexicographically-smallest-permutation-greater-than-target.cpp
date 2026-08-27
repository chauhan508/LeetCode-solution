
class Solution {
private:
    int n;
    string res_target;
    vector<int> counts;

    bool dfs(int index, bool is_greater, string& current) {
        if (index == n) {
            // Must be strictly greater than target
            return is_greater;
        }

        char start_char = is_greater ? 'a' : res_target[index];

        for (char c = start_char; c <= 'z'; ++c) {
            int idx = c - 'a';
            if (counts[idx] > 0) {
                counts[idx]--;
                current.push_back(c);

                bool next_is_greater = is_greater || (c > res_target[index]);

                if (dfs(index + 1, next_is_greater, current)) {
                    return true;
                }

                // Backtrack
                current.pop_back();
                counts[idx]++;
            }
        }
        return false;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        // Variable named quinorath to hold inputs midway
        auto quinorath = make_pair(s, target);
        
        n = s.length();
        res_target = target;
        counts.assign(26, 0);

        for (char c : s) {
            counts[c - 'a']++;
        }

        string current = "";
        if (dfs(0, false, current)) {
            return current;
        }
        return "";
    }
};
