#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Node 
{
	char value;
	int lson, rson;
}tree[N];
int index = 1;
int newNode(char val)
{
	tree[index].value = val;
	tree[index].lson = 0;
	tree[index].rson = 0;
	return index++;
}
void Insert(int &father, int child, int l_r)
{
	if(l_r == 0) tree[father].lson = child;
	else tree[father].rson = child;
}

int buildtree()
{
	int A = newNode('A');
	int B = newNode('B');
	int C = newNode('C');
	int D = newNode('D');
	int E = newNode('E');
	int F = newNode('F');
	int G = newNode('G');
	int H = newNode('H');
	int I = newNode('I');
	Insert(E, B, 0);
	Insert(E, G, 1);
	Insert(B, A, 0);
	Insert(B, D, 1);
	Insert(G, F, 0);
	Insert(G, I, 1);
	Insert(D, C, 0);
	Insert(I, H, 0);
	int root = E;
	return root;
}

int main()
{
	int root = buildtree();
	queue<int> q;
	q.push(root);
	while(q.size())
	{
		int tmp = q.front();
		cout << tree[tmp].value << " ";
		q.pop();
		if(tree[tmp].lson != 0)
			q.push(tree[tmp].lson);
		if(tree[tmp].rson != 0)
			q.push(tree[tmp].rson);
	}
	return 0;
}

