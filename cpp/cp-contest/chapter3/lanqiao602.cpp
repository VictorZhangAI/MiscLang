#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	string path;
};

char mp[31][51];
char k[4] = {'D', 'L', 'R', 'U'};
int dir[4][2] = {{1,0}, {0,-1}, {0,1}, {1,0}};
int vis[30][50];

char pre[31][51];

void print_path(int x, int y)
{
	if(x == 0 && y == 0) return;
	if(pre[x][y] == 'D') print_path(x - 1, y);
	if(pre[x][y] == 'L') print_path(x, y + 1);
	if(pre[x][y] == 'R') print_path(x, y - 1);
	if(pre[x][y] == 'U') print_path(x + 1, y);
	printf("%c", pre[x][y]);
}

void bfs()
{
	node start;
	start.x = 0;
	start.y = 0;
	start.path = "";
	vis[0][0] = 1;
	queue<node> q;
	q.push(start);
	while(!q.empty())
	{
		node.now = q.front();
		q.pop();
		if(now.x == 29 && now.y == 49)
		{
			cout << now.path << endl;
			print_path(29, 49);
			return;
		}
		for(int i = 0; i < 4; i++)
		{
			node next;
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(next.x < 0 || next.x >= 30 || next.y < 0 || next.y >= 50)
				continue;
			if(vis[next.x][next.y] == 1 || mp[next.x][next.y] == '1')
				continue;
			vis[next.x][next.y] = 1;
			next.path = now.path + k[i];
			pre[next.x][next.y] = k[i];
			q.push(next);
		}
	}
}

int main()
{
	for(int i = 0; i < 30; i++)
		cin >> mp[i];
	bfs();
	return 0;
}
