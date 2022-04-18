#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void)
{
	vector<long long>	list(3);

	cin >> list[0] >> list[1] >> list[2];
	sort(list.begin(), list.end());
	if (list[0] == list[1] && list[0] == 0)
		cout << list[2];
	else
		cout << list[0] + list[1] * list[2];
}
