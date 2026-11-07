class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int qLen = queries.size();
        
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<pair<int, int>> qSorted(qLen);
        for (int i = 0; i < qLen; ++i) {
            qSorted[i] = {queries[i], i};
        }
        sort(qSorted.begin(), qSorted.end());
        
        vector<int> ans(qLen);
        unordered_map<int, int> serverFreq;
        
        int left = 0, right = 0;
        
        for (auto& [qTime, origIdx] : qSorted) {
            int winStart = qTime - x;
            int winEnd = qTime;
            
            while (right < m && logs[right][1] <= winEnd) {
                serverFreq[logs[right][0]]++;
                right++;
            }
            
            while (left < m && logs[left][1] < winStart) {
                serverFreq[logs[left][0]]--;
                if (serverFreq[logs[left][0]] == 0) {
                    serverFreq.erase(logs[left][0]);
                }
                left++;
            }
            
            ans[origIdx] = n - serverFreq.size();
        }
        
        return ans;
    }
};
