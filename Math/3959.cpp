#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double	landingH;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(8);
}

double	ft_get_velocity(double h)
{
	double	ret;

	ret = sqrt(2 * 9.81 * h);
	return (ret);
}

double	ft_get_hh(int H, int L, double l)
{
	double	ret;

	if (l < 0)
		ret = H;
	else if (l < L / 2)
		ret = H * (1 - 2 * pow(l / L, 2));
	else if (l < L)
		ret = 2 * H * (pow((l / L) - 1, 2));
	else
		ret = 0;
	return (ret);
}

double	ft_get_landing_fh(int L, int H, double l, int p, double startV)
{
	double	ret;

	ret = -(9.81 / 2) * pow(l / startV, 2) + H + p;
	return (ret);
}

double	ft_get_landing_X(double L, double H, double p, double startV)
{
	double	st;
	double	ed;
	double	mid;
	double	height;

	st = 0.0;
	ed = (double) L * 100000;
	while (ed - st > 1e-9)
	{
		mid = (st + ed) / 2;
		landingH = ft_get_landing_fh(L, H, mid, p, startV);
		height = ft_get_hh(H, L, mid);
		if (landingH > height)
			st = mid;
		else
			ed = mid;
	}
	return (mid);
}

double	ft_get_der_f(double landingX, double landingV)
{
	double	ret;

	ret = -9.81 * landingX / pow(landingV, 2);
	return (ret);
}

double	ft_get_der_h(double landingX, double L, double H)
{
	double	ret;

	if (landingX < 0 || landingX >= L)
		ret = 0; 	
	else if (landingX < L / 2)
		ret = -4 * H * landingX / pow(L, 2);
	else if (landingX < L)
		ret = 4 * H * ((landingX / L) - 1) / L;
	return (ret);
}

double	ft_get_theta(double landingX, double startV, double L, double H)
{
	double	derF;
	double	derH;
	double	cosTheta;
	double	ret;
	double	piValue;

	derF = ft_get_der_f(landingX, startV);
	derH = ft_get_der_h(landingX, L, H);
	cosTheta = (1 + (derF * derH)) / (sqrt(1 + pow(derF, 2)) * sqrt(1 + pow(derH, 2)));
	piValue = 3.14159265358979;
	ret = acos(cosTheta) * 180.0 / piValue;
	return (ret);
}

void	ft_get_solution(void)
{
	int	T;
	double	j, p, H, L;
	double	startV, landingV;
	double	landingX;
	double	xLocate;
	double	theta;

	cin >> T;
	while (T--)
	{
		cin >> j >> p >> H >> L;
		startV = ft_get_velocity(j);
		landingX = ft_get_landing_X(L, H, p, startV);
		landingV = ft_get_velocity(j + p + H - landingH);
		theta = ft_get_theta(landingX, startV, L, H);
		cout << landingX << " " << landingV << " " << theta << '\n';
	}
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
