#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

char mat[8][8], visit[8][8];
int n, m, t;
int flag;
int a, b, c, d;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
#define CHECK(xx,yy) (xx >= 0 && xx < n && yy >= 0 && yy < m)
void dfs(int x, int y, int time)
{
	if(flag) return;
	if(mat[x][y] == 'D')
	{
		if(time == t)
			flag = 1;
		return;
	}
	int tmp = t - time - abs(c - x) - abs(d - y);
	if(tmp < 0) return;
	for(int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(CHECK(xx,yy) && mat[xx][yy] != 'X' 
		&& !visit[xx][yy])
		{
			visit[xx][yy] = 1;
			dfs(xx, yy, time + 1);
			visit[xx][yy] = 0;
		}
	}
	return;
}

int main()
{
	while(~scanf("%d%d%d", &n, &m, &t))
	{
		if(n == 0 && m == 0 && t == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				if(mat[i][j] == 'S') a = i, b = j;
				if(mat[i][j] == 'D') c = i, d = j;
			}
		}
		memset(visit, 0, sizeof(visit));
		int tmp = t - abs(c - a) - abs(d - b);
		if(tmp & 1)
		{
			puts("NO");
			continue;
		}
		flag = 0;
		visit[a][b] = 1;
		dfs(a, b, 0);
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}