class Solution {
public:

    vector<int> dp;

    long solve(vector<int>& coins, int rem)
    {
        if(rem == 0) return 0;
        if(rem < 0) return INT_MAX;
        if(dp[rem] != -1) return dp[rem];

        long res = INT_MAX;
        for(int coin : coins)
        {
            res = min(res, 1 + solve(coins, rem - coin));
        }

        return dp[rem] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        int res = solve(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};
