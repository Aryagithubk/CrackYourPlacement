class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int total_cells = m * n;

        // Result array and storing queries with their original indices
        vector<pair<int, int>> query_with_index;
        for (int i = 0; i < queries.size(); ++i) {
            query_with_index.push_back({queries[i], i});
        }

        // Sort queries based on value
        sort(query_with_index.begin(), query_with_index.end());

        // Direction vectors for moving in 4 directions
        vector<int> directions = {0, 1, 0, -1, 0};
        
        // Visited array to keep track of visited cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Answer array to store result for each query
        vector<int> ans(queries.size(), 0);

        // Priority queue to process grid cells in increasing order of values
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Start BFS from the top-left corner (0, 0)
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        int points = 0;

        for (auto &[query_value, query_idx] : query_with_index) {
            // Expand the flood fill as long as current grid values are smaller than the query value
            while (!pq.empty() && pq.top().first < query_value) {
                auto [cell_value, pos] = pq.top();
                pq.pop();
                int row = pos.first;
                int col = pos.second;

                // Count the current cell
                points++;

                // Move in 4 directions (up, down, left, right)
                for (int i = 0; i < 4; ++i) {
                    int new_row = row + directions[i];
                    int new_col = col + directions[i + 1];

                    // Check if the new position is within bounds and not visited
                    if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !vis[new_row][new_col]) {
                        vis[new_row][new_col] = true;
                        pq.push({grid[new_row][new_col], {new_row, new_col}});
                    }
                }
            }

            // Store the result for this query
            ans[query_idx] = points;
        }

        return ans;
    }
};
