#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> q;
	string s;
	while(getline(cin, s) && s != "END")
	{
		sort(s.begin(), s.end());
		int num = 1;
		for(int i = 1; i <= s.length(); i++)
		{
			if(s[i] != s[i - 1])
			{
				q.push(num);
				num = 1;
			}
			else
				num++;
		}
		int ans = 0;
		if(q.size() == 1)
			ans = s.length();
		while(q.size() > 1)
		{
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			q.push(a + b);
			ans += a + b;
		}
		q.pop();
		printf("%d %d %.1f\n", 
		s.length() * 8, 
		ans, 
		(double)s.length() * 8 / (double)ans);
	}
	return 0;
}
