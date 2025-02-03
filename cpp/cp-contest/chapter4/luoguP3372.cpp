#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
#define lowbit(x) ((x) & - (x))
ll tree1[N], tree2[N];

void update1(ll x, ll d)
{
	while(x <= N)
	{
		tree1[x] += d;
		x += lowbit(x);
	}
}

void update2(ll x, ll d)
{
	while(x <= N)
	{
		tree2[x] += d;
		x += lowbit(x);
	}
}

ll sum1(ll x)
{
	ll ans = 0;
	while(x > 0)
	{
		ans += tree1[x];
		x -= lowbit(x);
	}
	return ans;
}

ll sum2(ll x)
{
	ll ans = 0;
	while(x > 0)
	{
		ans += tree2[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll old = 0, a;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		update1(i, a - old);
		update2(i, (i - 1) * (a - old));
		old = a;
	}
	while(m--)
	{
		ll q, L, R, d;
		scanf("%lld", &q);
		if(q == 1)
		{
			scanf("%lld%lld%lld", &L, &R, &d);
			update1(L, d);
			update1(R + 1, -d);
			update2(L, d * (L - 1));
			update2(R + 1, -d * R);
		}
		else
		{
			scanf("%lld%lld", &L, &R);
			printf("%lld\n", R*sum1(R)-sum2(R)-(L-1)*sum1(L-1)+sum2(L-1));
		}
	}
	return 0;
}