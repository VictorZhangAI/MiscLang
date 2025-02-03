#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int s[N];
int d[N];
int ans;

void init_set()
{
	for(int i = 1; i <= N; i++)
	{
		s[i] = i;
		d[i] = 0;
	}
}

int find_set(int x)
{
	if(x != s[x])
	{
		int t = s[x];
		s[x] = find_set(s[x]);
		d[x] += d[t];
	}
	return s[x];
}

void merge_set(int a, int b, int v)
{
	int roota = find_set(a), rootb = find_set(b);
	if(roota == rootb)
	{
		if(d[a] - d[b] != v) ans++;
	}
	else
	{
		s[roota] = rootb;
		d[roota] = d[b] - d[a] + v;
	}
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init_set();
		ans = 0;
		while(m--)
		{
			int a, b, v;
			scanf("%d%d%d", &a, &b, &v);
			a--;
			merge_set(a, b, v);
		}
		printf("%d\n", ans);
	}
	return 0;
}