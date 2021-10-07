#include <iostream>

using namespace std;

const int MAX = 5000000;
const int PRIME_MAX = 190000;

bool primeCheck[MAX + 1];
int primeList[PRIME_MAX];
int primeCount;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < (MAX / 2) + 1; i++)
	{
		if (!primeCheck[i])
		{
			primeList[primeCount++] = i;
			for (int j = 2; (j * i) < MAX; j++)
				primeCheck[j * i] = true;
		}
	}

	int tcc;

	cin >> tcc;

	while (tcc--)
	{
		int value;
		cin >> value;

		while (value > 1)
		{
			// Not Prime
			if (primeCheck[value])
			{
				for (int i = 0; i < primeCount; i++)
				{
					if (value % primeList[i] == 0)
					{
						cout << primeList[i] << ' ';
						value /= primeList[i];
						break;
					}
				}
			}
			// Prime
			else
			{
				cout << value;
				value = 1;
			}
		}

		cout << '\n';
	}
}