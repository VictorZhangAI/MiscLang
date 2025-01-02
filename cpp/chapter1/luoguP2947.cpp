#include<bits/stdc++.h>
using namespace std;
int h[100000], ans[100000];
int main()
{
	stack<int> s;
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		while(!s.empty() && h[s.top()] <= h[i])
			s.pop();
		if(s.empty())
			ans[i] = 0;
		else
			ans[i] = s.top();
		s.push(i);
	}
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}