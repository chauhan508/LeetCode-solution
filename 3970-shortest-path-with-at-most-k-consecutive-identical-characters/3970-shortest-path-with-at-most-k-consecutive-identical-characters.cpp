
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
     
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

   
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

       
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;


        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();

            if (d > dist[u][run]) continue;

         
            if (u == n - 1) return d;

            for (const auto& [v, weight] : adj[u]) {
                int next_run = (labels[v] == labels[u]) ? (run + 1) : 1;


                if (next_run > k) continue;

                
                if (d + weight < dist[v][next_run]) {
                    dist[v][next_run] = d + weight;
                    pq.push({dist[v][next_run], v, next_run});
                }
            }
        }

       
        int min_ans = INF;
        for (int r = 1; r <= k; ++r) {
            min_ans = min(min_ans, dist[n - 1][r]);
        }

        return (min_ans == INF) ? -1 : min_ans;
    }
};
