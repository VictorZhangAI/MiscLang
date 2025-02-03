#include<iostream>
#include<cstdio>
using namespace std;

const int N = 50005;
int s[N];
int d[N];
int ans;

void init_set()
{
	for(int i = 0; i <= N; i++)
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
		d[x] = (d[x] + d[t]) % 3;
	}
	return s[x];
}

void merge_set(int x, int y, int relation)
{
	int rootx = find_set(x), rooty = find_set(y);
	if(rootx == rooty)
	{
		if((relation - 1) != (d[x] - d[y] + 3) % 3)
			ans++;
	}
	else
	{
		s[rootx] = rooty;
		d[rootx] = (d[y] - d[x] + relation - 1) % 3;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	init_set();
	ans = 0;
	while(k--)
	{
		int relation, x, y;
		scanf("%d%d%d", &relation, &x, &y);
		if(x > n || y > n 
		|| (relation == 2 && x == y))
			ans++;
		else
			merge_set(x, y, relation);
	}
	cout << ans;
	return 0;
}