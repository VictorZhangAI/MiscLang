#include<bits/stdc++.h>

using namespace std;

int w[] = {1, 2, 3};
int v[] = {6, 10, 12};
int dp[1001] = {0};
int n = 3, C = 5;

int main()
{
	for(int i = 1; i <= 3; i++)
	{
		for(int j = w[i]; j <= C; j++)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[5] << endl;
	return 0;
}
