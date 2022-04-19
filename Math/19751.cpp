#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void)
{
	vector<int>	list(4);

	for (int i=0; i<4; i++)
		cin >> list[i];
	sort(list.begin(), list.end());
	cout << list[0] << " " << list[2] << " " << list[1] << " " << list[3];
}

