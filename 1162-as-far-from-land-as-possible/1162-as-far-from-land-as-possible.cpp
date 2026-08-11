class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Land = -1 means source / distance 0
        // Water = 0 means unvisited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        int maxDistance = -1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 0) {

                    // Land(-1) -> distance 0
                    // Water distance = parent distance + 1
                    int currentDistance = (grid[row][col] == -1)
                                            ? 0
                                            : grid[row][col];

                    grid[nr][nc] = currentDistance + 1;

                    maxDistance = max(maxDistance, grid[nr][nc]);

                    q.push({nr, nc});
                }
            }
        }

        return maxDistance;
    }
};