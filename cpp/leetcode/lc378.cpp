class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> arr;
        int idx = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr.push_back(matrix[i][j]);
        std::sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};
