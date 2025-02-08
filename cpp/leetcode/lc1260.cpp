class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        deque<int> dq;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dq.push_back(grid[i][j]);
        for(int i = 0; i < k; i++)
        {
            int tmp = dq.back();
            dq.pop_back();
            dq.push_front(tmp);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = dq.front(), dq.pop_front();
        
        return grid;
    }
};
