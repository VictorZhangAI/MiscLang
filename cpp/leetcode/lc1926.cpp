class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();

        pair<int, int> start = {entrance[0], entrance[1]};
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, start});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[start.first][start.second] = 1;
        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int step = q.front().first;
            if(start != q.front().second &&
            (x == 0 || y == 0 || x == n - 1 || y == m - 1))
                return step;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m &&
                maze[nr][nc] == '.' && vis[nr][nc] == 0)
                {
                    q.push({step + 1, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};
