class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // Free heap: stores {weight, index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> freeServers;
        // Busy heap: stores {free_time, weight, index}
        priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<tuple<long long, long long, int>>> busyServers;

        for (int i = 0; i < servers.size(); ++i) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(tasks.size());
        long long curr_time = 0;

        for (int j = 0; j < tasks.size(); ++j) {
            curr_time = max(curr_time, (long long)j);

            // Move servers from busy to free if their task is finished
            while (!busyServers.empty() && get<0>(busyServers.top()) <= curr_time) {
                auto [free_time, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }

            // If no free servers are available, jump time to the next available server
            if (freeServers.empty()) {
                curr_time = get<0>(busyServers.top());
                while (!busyServers.empty() && get<0>(busyServers.top()) <= curr_time) {
                    auto [free_time, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }

            // Assign task j to the best available server
            auto [w, idx] = freeServers.top();
            freeServers.pop();
            ans[j] = idx;
            busyServers.push({curr_time + tasks[j], w, idx});
        }

        return ans;
    }
};
