class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& comp, int id) {
        comp[node] = id;

        for (int nxt : adj[node]) {
            if (comp[nxt] == -1) {
                dfs(nxt, adj, comp, id);
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            adj[i].push_back(i);
        }

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }

        // Find connected components
        vector<int> comp(n, -1);
        int id = 0;

        for (int i = 0; i < n; i++) {
            if (comp[i] == -1) {
                dfs(i, adj, comp, id);
                id++;
            }
        }

        // Answer queries
        vector<bool> res;
        for (auto &q : queries) {
            res.push_back(comp[q[0]] == comp[q[1]]);
        }

        return res;
    }
};