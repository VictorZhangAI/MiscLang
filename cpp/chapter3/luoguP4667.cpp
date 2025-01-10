#include<bits/stdc++.h>
using namespace std;

const int dir[4][2] = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};
const int ab[4] = {2, 1, 1, 2};
const int cd[4][2] = {{-1,-1}, {-1,0}, {0,-1}, {0,0}};
int graph[505][505], dis[505][505];

struct P
{
	int x, y, dis;
}u;

int read_ch()
{
	char c;
	while(c = getchar() != '/' && c != '\\');
	return c == '/' ? 1 : 2;
}

int main()
{
	int n, m;
	cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			graph[i][j] = read_ch();
	deque<P> dq;
	dq.push_back((P){1,1,0});
	dis[1][1] = 0;
	while(!dq.empty())
	{
		u = dq.front();
		dq.pop_front();
		int nx, ny;
		for(int i = 0; i <= 3; i++)
		{
			nx = u.x + dir[i][0];
			ny = u.y + dir[i][1];
			int d = 0;
			d = graph[u.x + cd[i][0]][u.y + cd[i][1]] != ab[i];
			if(nx && ny && nx < n + 2 && ny < m + 2 
			&& dis[nx][ny] > dis[u.x][u.y] + d)
			{
				dis[nx][ny] = dis[u.x][u.y] + d;
				if(d == 0)
					dq.push_front((P){nx, ny, dis[nx][ny]});
				else
					dq.push_back((P){nx, ny, dis[nx][ny]});
				if(nx == n + 1 && ny == m + 1)
					break;
			}
		}
	}
	if(dis[n + 1][m + 1] != 0x3f3f3f3f)
		cout << dis[n + 1][m + 1];
	else
		cout << "NO SOLUTION";
	return 0;
}