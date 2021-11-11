#include <iostream>
#include <queue>

using namespace std;

void fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int	get_max_sum_of_pair_number_from_queue(priority_queue<int> &pq, int sign, int zeroCnt)
{
	int	a, b;
	int	sum;

	sum = 0;
	while (!pq.empty())
	{
		if (pq.size() == 1)
			break ;
		if (pq.top() == 1 and sign == 1)
			break ;
		a = pq.top();
		pq.pop();
		if (pq.top() == 1 and sign == 1)
		{
			pq.push(a);
			break ;
		}
		b = pq.top();
		pq.pop();
		sum += a * b;
	}
	while (!pq.empty())
	{
		if (sign == -1 and zeroCnt)
			break ;
		sum += pq.top() * sign;
		pq.pop();
	}
	return (sum);
}

void get_solution(void)
{
	int					N, temp;
	int					ans;
	int					zeroCnt;
	priority_queue<int>	minusQ;
	priority_queue<int>	plusQ;	

	cin >> N;
	zeroCnt = 0;
	while (N--)
	{
		cin >> temp;
		if (temp > 0)
			plusQ.push(temp);
		else if (temp < 0)
			minusQ.push(-temp);
		else
			zeroCnt++;
	}
	ans = get_max_sum_of_pair_number_from_queue(plusQ, 1, zeroCnt);
	ans += get_max_sum_of_pair_number_from_queue(minusQ, -1, zeroCnt);
	cout << ans;
}

int main(void)
{
    fast_io();
	get_solution();
}
