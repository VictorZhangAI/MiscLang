#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & - (x))
const int N = 100010;
int tree[N] = {0};

void update(int x, int d)
{
	while(x <= N)
	{
		tree[x] += d;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; i++)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			update(L, 1);
			update(R + 1, -1);
		}
		for(int i = 1; i <= n; i++)
		{
			if(i != n) printf("%d ", sum(i));
			else printf("%d\n", sum(i));
		}
	}
	return 0;
}