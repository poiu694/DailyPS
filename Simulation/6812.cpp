#include <iostream>

using namespace std;

int	convert_time(int time)
{
	int	flag;
	int	temp;

	flag = 0;
	if (time < 0)
		time = time + 2400;
	else if (time >= 2400)
	{
		flag = 1;
		time = time - 2400;
	}
	temp = time;
	if (time % 100 >= 60)
	{
		time = time / 100;
		time = time + 1;
		time = time * 100;
		time += temp % 100 - 60;
	}
	if (time >= 2400)
		time = time - 2400;
	return (time);
}

int	main(void)
{
	int	N;

	cin >> N;
	cout << convert_time(N) << " in Ottawa\n";
	cout << convert_time(N - 300) << " in Victoria\n";
	cout << convert_time(N - 200) << " in Edmonton\n";
	cout << convert_time(N - 100) << " in Winnipeg\n";
	cout << convert_time(N) << " in Toronto\n";
	cout << convert_time(N + 100) << " in Halifax\n";
	cout << convert_time(N + 130) << " in St. John's\n";
}
