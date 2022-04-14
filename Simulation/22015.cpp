#include <iostream>
#include <cmath>
using namespace std;

int	main(void)
{
	int	a, b, c;
	int	mx;
	int	ans;

	cin >> a >> b >> c;
	mx = max(a, max(b, c));
	ans = 0;
	ans += abs(mx - a);
	ans += abs(mx - b);
	ans += abs(mx - c);
	cout << ans;
}
