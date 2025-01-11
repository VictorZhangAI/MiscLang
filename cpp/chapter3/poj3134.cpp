#include<stdio.h>
#include<string.h>

const int N = 100;

int num[N];

int n, depth;

bool dfs(int now, int d)
{
	if(d > depth)
		return false;
	if(now == n)
		return true;
	if(now << (depth - d) < n)
		return false;
	num[d] = now;
	for(int i = 0; i <= d; i++)
	{
		if(dfs(now + num[i], d + 1))
			return true;
		else if(dfs(now - num[i], d + 1))
			return false;
	}
	return false;
}

int main()
{
	while(~scanf("%d", &n) && n)
	{
		for(depth = 0;;depth++)
		{
			memset(num, 0, sizeof(num));
			if(dfs(1, 0))
				break;
		}
		printf("%d\n", depth);
	}
	return 0;
}