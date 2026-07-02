class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        // Health remaining after entering the starting cell
        health -= grid[0][0];

        if (health < 1)
            return false;

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, health});
        best[0][0] = health;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, h] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {

                int x = r + dx[i];
                int y = c + dy[i];

                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;

                int newHealth = h - grid[x][y];

                if (newHealth < 1)
                    continue;

                // Already reached with equal or more health
                if (best[x][y] >= newHealth)
                    continue;

                best[x][y] = newHealth;
                q.push({x, y, newHealth});
            }
        }

        return false;
    }
};