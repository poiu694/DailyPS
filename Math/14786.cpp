#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(20);
}

double	ft_get_deriavtion_value(int A, int B, int C, double value)
{
	double	ret;

	ret = A + (B * cos(value));
	return (ret);
}

double	ft_get_function_value(int A, int B, int C, double value)
{
	double	ret;

	ret = (A*value) + (B * sin(value)) - C;
	return (ret);
}

double	ft_get_next_x(int A, int B, int C, double value)
{
	return (value - (ft_get_function_value(A, B, C, value)
						/ ft_get_deriavtion_value(A, B, C, value)));
}

double	ft_get_err(double xOld, double xNew)
{
	double	ret;

	ret = abs((xNew - xOld) / xOld);
	return (ret);
}

double	ft_calculate_newton_method(int A, int B, int C)
{
	double	xOld;
	double	xNew;
	double	tol;
	double	err;
	double	ret;

	xOld = 1.0;
	err = 1e-9;
	tol = 1.0;
	while (tol > err)
	{
		xNew = ft_get_next_x(A, B, C, xOld);
		tol = ft_get_err(xOld, xNew);
		if (tol < err)
		{
			ret = xNew;
			break ;
		}
		xOld = xNew;
	}
	return (ret);
}

void	ft_get_solution(void)
{
	int	A;
	int	B;
	int	C;

	cin >> A >> B >> C;
	cout << ft_calculate_newton_method(A, B, C);
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}

