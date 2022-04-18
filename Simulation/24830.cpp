#include <iostream>

using namespace std;

int	main(void)
{
	int		N;
	long long	a, b;
	long long	past;
	long long	cal_val;
	char		op;

	cin >> N;
	past = 1;
	while (N--)
	{
		cin >> a >> op >> b;
		switch(op)
		{
			case '+':
				cal_val = a + b - past;
				break ;
			case '-':
				cal_val = a - b;
				cal_val *= past;
				break ;
			case '*':
				cal_val = a * a * b * b;
				break ;
			case '/':
				if (a % 2 == 0)
					cal_val = a / 2;
				else
					cal_val = (a + 1) / 2;
				break ;
		}
		past = cal_val;
		cout << cal_val << '\n';
	}
}
