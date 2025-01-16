#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, m, a[N], tree[N];
int lowbit(int x) {return (x & -x);}

void update1(int x, int value)
{
	while(x <= n)
	{
		tree[x] = value;
		for(int i = 1; i < lowbit(x); i <<= 1)
			tree[x] = max(tree[x], tree[x - i]);
		x += lowbit(x);
	}
}

int query1(int L, int R)
{
	int ans = 0;
	while(L <= R)
	{
		ans = max(ans, a[R]);
		R--;
		while(R-L >= lowbit(R))
		{
			ans = max(ans, a[R]);
			R -= lowbit(R);
		}
	}
	return ans;
}

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			update1(i, a[i]);
		}
		while(m--)
		{
			char s[5]; int A, B;
			scanf("%s%d%d", s, &A, &B);
			if(s[0] == 'Q')
				printf("%d\n", query1(A, B));
			else
			{
				a[A] = B;
				update1(A, B);
			}
		}
	}
	return 0;
}