#include<bits/stdc++.h>
using namespace std;
int sum = 0, m;
void hanoi(char x, char y, char z, int n)
{
	if(n == 1)
	{
		sum++;
		if(sum == m) 
			cout << "#" << n << ":" << x << "->" << z << endl;
	}
	else
	{
		hanoi(x, z, y, n - 1);
		sum++;
		if(sum == m) 
			cout << "#" << n << ":" << x << "->" << z << endl;
		hanoi(y, x, z, n - 1);
	}
}
int main()
{
	int n; cin >> n >> m;
	hanoi('A', 'B', 'C', n);
	cout << sum << endl;
	return 0;
}
