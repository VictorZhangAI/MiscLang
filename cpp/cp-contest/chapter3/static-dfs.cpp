#include<iostream>
#include<cstdio>
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

void insert(int &father, int child, int l_r)
{
	if(l_r == 0) tree[father].lson = child;
	else tree[father].rson = child;
}

int dfn[N] = {0};
int dfn_timer = 0;

void dfn_order(int father)
{
	if(father != 0)
	{
		dfn[father] = ++dfn_timer;
		printf("dfn[%c] = %d;\n", tree[father].value, dfn[father]);
		dfn_order(tree[father].lson);
		dfn_order(tree[father].rson);
	}
}

int visit_timer = 0;

void visit_order(int father)
{
	if(father != 0)
	{
		printf("visit[%c] = %d;\n", tree[father].value, ++visit_timer);
		visit_order(tree[father].lson);
		visit_order(tree[father].rson);
	}
}

int deep[N] = {0};
int deep_timer = 0;

void deep_node(int father)
{
	if(father != 0)
	{
		deep[father] = ++deep_timer;
		printf("deep[%c] = %d;\n", tree[father].value, deep[father]);
		deep_node(tree[father].lson);
		deep_node(tree[father].rson);
		deep_timer--;
	}
}

int num[N] = {0};
int num_node(int father)
{
	if(father != 0) return 0;
	else 
	{
		num[father] = num_node(tree[father].lson) + num_node(tree[father].rson) + 1;
		printf("num[%c] = %d;\n", tree[father].value, num[father]);
		return num[father];
	}
}

void preorder(int father)
{
	if(father != 0)
	{
		cout << tree[father].value << " ";
		preorder(tree[father].lson);
		preorder(tree[father].rson);
	}
}

void inorder(int father)
{
	if(father != 0)
	{
		inorder(tree[father].lson);
		cout << tree[father].value << " ";
		inorder(tree[father].rson);
	}
}

void postorder(int father)
{
	if(father != 0)
	{
		postorder(tree[father].lson);
		postorder(tree[father].rson);
		cout << tree[father].value << " ";
	}
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
	insert(E, B, 0);
	insert(E, G, 1);
	insert(B, A, 0);
	insert(B, D, 1);
	insert(G, F, 0);
	insert(G, I, 1);
	insert(D, C, 0);
	insert(I, H, 0);
	int root = E;
	return root;
}

int main()
{
	int root = buildtree();
	cout << "dfn order:"; dfn_order(root); cout << endl;
	cout << "visit order:"; visit_order(root); cout << endl;
	cout << "deep order:"; deep_node(root); cout << endl;
	cout << "num of tree:"; num_node(root); cout << endl;
	cout << "in order:"; inorder(root); cout << endl;
	cout << "pre order:"; preorder(root); cout << endl;
	cout << "post order:"; postorder(root); cout << endl;
	return 0;
}
