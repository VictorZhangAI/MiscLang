class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.empty())
            return 0;

        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});
        int maxEffort = 0;
        set<string> visited;

        while(!minHeap.empty())
        {
            auto current = minHeap.top();
            minHeap.pop();
            int effort = current[0];
            int curRow = current[1];
            int curCol = current[2];

            maxEffort = max(maxEffort, effort);
            if(curRow == rows - 1 && curCol == cols - 1)
            {
                return maxEffort;
            }
            visited.insert(to_string(curRow) + "," + to_string(curCol));

            vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto direction : directions)
            {
                int newRow = curRow + direction[0];
                int newCol = curCol + direction[1];

                if(0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols && visited.find(to_string(newRow) + "," + to_string(newCol)) == visited.end())
                {
                    int newEffort = abs(heights[newRow][newCol] - heights[curRow][curCol]);
                    minHeap.push({newEffort, newRow, newCol});
                }
            }
        }
        return maxEffort;
    }
};
