#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int quicksort(int left, int right, int k)
{
	int mid = a[left + (right - left) / 2];
	int i = left, j = right - 1;
	while(i <= j)
	{
		while(a[i] < mid) ++i;
		while(a[j] > mid) --j;
		if(i <= j)
		{
			swap(a[i], a[j]);
			++i, --j;
		}
	}
	if(left <= j && k <= j) return quicksort(left, j + 1, k);
	if(i < right && k >= i) return quicksort(i, right, k);
	return a[k];
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int k = n / 2;
	printf("%d\n", quicksort(0, n, k));
	return 0;
}