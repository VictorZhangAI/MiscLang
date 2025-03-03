class Solution {
public:

    void backtrack(string& s, int start, 
    vector<string>& path, vector<vector<string>>& result,
    vector<vector<bool>> dp)
    {
        if(start == s.length())
        {
            result.push_back(path);
            return;
        }

        for(int end = start; end < s.length(); end++)
        {
            if(dp[start][end])
            {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, result, dp);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for(int length = 2; length <= n; length++)
        {
            for(int i = 0; i <= n - length; i++)
            {
                int j = i + length - 1;
                if(s[i] == s[j] && (length == 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                }
            }
        }
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result, dp);
        return result;
    }
};
