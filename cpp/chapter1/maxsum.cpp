#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int main()
{
	int t; cin >> t;
	for(int k = 1; k <= t; k++)
	{
		int n; cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> dp[i];
		int start = 1, end = 1, p = 1;
		int maxsum = dp[1];
		for(int i = 2; i <= n; i++)
		{
			if(dp[i - 1] + dp[i] >= dp[i])
				dp[i] = dp[i - 1] + dp[i];
			else
				p = i;
			if(dp[i] > maxsum)
			{
				maxsum = dp[i];
				start = p;
				end = i;
			}
		}
		printf("Case %d:\n", k);
		printf("%d %d %d\n", maxsum, start, end);
		if(k != t) cout << endl;
	}
	return 0;
}