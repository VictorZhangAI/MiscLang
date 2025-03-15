class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<int> check(n + 1, 1);
        for(int i = 2; i < n; i++)
        {
            if(check[i] == 1)
            {
                cnt++;
                for(long long j = (long long)i * i; j < n; j += i)
                {
                    check[j] = 0;
                }
            }
        }
        return cnt;
    }
};
