#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int	main(void)
{
	int	cnt;
	int	k, p;
	string	target;

	cin >> target;
	cnt = 1;
	k = p = 0;
	if (target[0] == 'K')
		k++;
	else
		p++;
	for (int i=1; i<target.length(); i++)
	{
		if (target[i] == 'K')
		{
			k++;
			if (p)
				p--;
		}
		else
		{
			p++;
			if (k)
				k--;
		}
		cnt = max(cnt, max(k, p));
	}
	cout << cnt;
}
