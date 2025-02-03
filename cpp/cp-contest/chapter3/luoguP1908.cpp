#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x) & - (x))
const int N = 500010;
int tree[N], rank[N], n;

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

struct point
{
	int num, val;
}a[N];

bool cmp(point x, point y)
{
	if(x.val == y.val)
		return x.num < y.num;
	return x.val < y.val;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].val);
		a[i].num = i;
	}
	std::sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++)
		rank[a[i].num] = i;
	long long ans = 0;
	for(int i = n; i > 0; --i)
	{
		update(rank[i], 1);
		ans += sum(rank[i] - 1);
	}
	printf("%lld", ans);
	return 0;
}