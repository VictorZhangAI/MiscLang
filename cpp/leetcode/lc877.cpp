class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp = piles;
        for(int d = 1; d < piles.size(); d++)
        {
            for(int i = 0; i < piles.size() - d; i++)
            {
                dp[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};
