#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void)
{
	vector<int>	list(3);
	cin >> list[0] >> list[1] >> list[2];
	sort(list.begin(), list.end());
	if ((list[0] == list[1]) || (list[1] == list[2]))
		cout << "S";
	else if (list[0] + list[1] == list[2])
		cout << "S";
	else
		cout << "N";
}
