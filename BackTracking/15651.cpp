#include <iostream>
#include <vector>

using namespace std;

int	N, M;
vector<int>	list;

void	go(int num)
{
	if (list.size() == M)
	{
		for (int a: list)
			cout << a << " ";
		cout << '\n';
		return ;
	}
	for (int i=1; i<=N; i++)
	{
		list.push_back(i);
		go(i);
		list.pop_back();
	}
}

int	main(void)
{
	cin >> N >> M;
	for (int i=1; i<=N; i++)
	{
		list.push_back(i);
		go(i);
		list.pop_back();
	}
}
