#include <iostream>
#include <stack>

using namespace std;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void	solve(void)
{
	int				N;
	int				ans;
	stack<int>		st;

	ans = 0;
	cin >> N;
	while (N--)
	{
		int x, height;
		cin >> x >> height;

		if (height == 0)
		{
			ans += st.size();
			while (!st.empty()) st.pop();
			continue ; 
		}
		while (!st.empty() && st.top() > height)
		{
			ans += 1;
			st.pop();
		}
		if (!st.empty() && st.top() == height)
			continue ;
		st.push(height);
	}
	ans += st.size();
	cout << ans;
}

int	main(void)
{
	fast_io();
	solve();
}
