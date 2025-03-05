class Solution {
public:

    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n
            && j >= 0 && j < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        int et = 0;
        while(!q.empty())
        {
            et++;
            int sze = q.size();
            while(sze--)
            {
                vector<int> curr = q.front();
                q.pop();
                int i = curr[0];
                int j = curr[1];
                for(auto it : dir)
                {
                    int x = i + it[0];
                    int y = j + it[1];
                    if(isSafe(x, y, n, m) && grid[x][y] == 1)
                    {
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return max(0, et - 1);
    }
};
