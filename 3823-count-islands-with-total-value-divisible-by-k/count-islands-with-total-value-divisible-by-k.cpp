
class Solution {
public:
    long long dfs(int row, int col,
                  vector<vector<int>>& vis,
                  vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        long long sum = grid[row][col];

        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] != 0 &&
                !vis[nrow][ncol]) {

                sum += dfs(nrow, ncol, vis, grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(i, j, vis, grid);

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
