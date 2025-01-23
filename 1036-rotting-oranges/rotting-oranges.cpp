class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0, total = 0;
        queue<pair<int, int>> q;
        int days = 0;
        int n = grid.size(), m = grid[0].size();

        if (n == 0) {
            return 0;
        }

        // Count total oranges and push rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) { // Count all oranges (fresh or rotten)
                    total++;
                }
                if (grid[i][j] == 2) { // Add initially rotten oranges to the queue
                    q.push({i, j});
                }
            }
        }

        // Directions for moving (right, left, down, up)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Perform BFS to rot all connected fresh oranges
        while (!q.empty()) {
            int sz = q.size(); // Number of rotten oranges in the current level
            cnt += sz;         // Update count of processed oranges

            while (sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // Traverse all four directions
                for (int i = 0; i < 4; i++) {
                    int sx = x + dx[i];
                    int sy = y + dy[i];

                    // Check boundaries and if the cell contains a fresh orange
                    if (sx < 0 || sx >= n || sy < 0 || sy >= m || grid[sx][sy] != 1) {
                        continue;
                    }

                    // Mark fresh orange as rotten and push to the queue
                    grid[sx][sy] = 2;
                    q.push({sx, sy});
                }
            }

            // Increment days after processing all rotten oranges at the current level
            if (!q.empty()) {
                days++;
            }
        }

        // If all oranges are processed, return days; otherwise, return -1
        return (cnt == total) ? days : -1;
    }
};
