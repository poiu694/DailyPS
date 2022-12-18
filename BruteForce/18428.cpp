#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

queue<pii>	q;
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};

bool	bfs(int N, vector<char> map[10])
{
	while (!q.empty())
	{
		int	x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0; i<4; i++)
		{
			int nx = x;
			int ny = y;

			while (true)
			{
				nx += dx[i];
				ny += dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					break ;
				if (map[nx][ny] == 'O')
					break ;
				else if (map[nx][ny] == 'S')
				{
					// 학생이 걸린 경우
					return (false);
				}
			}
		}
	}
	// 모든 학생이 걸리지 않은 경우
	return (true);
}

int	main(void)
{
	int	N;
	vector<char>	map[10];
	vector<char>	tempMap[10];

	cin >> N;
	for (int i=0; i<N; i++)
	{
		map[i].resize(N);
		tempMap[i].resize(N);
		for (int j=0; j<N; j++)
		{
			cin >> map[i][j];
		}
	}

	int	powN = pow(N, 2);
	// bruteforce
	for (int brute=0; brute<powN*powN*powN; brute++)
	{
		// copyMap
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<N; j++)
			{
				tempMap[i][j] = map[i][j];
				if (map[i][j] == 'T')
					q.push({ i, j });
			}
		}

		bool flag = true; // 중복되지 않게 장애물을 세웠는가?
		int	pastXY = -1;
		int temp = brute;
		// 3개의 장애물을 놓는다.
		for (int i=0; i<3; i++)
		{
			int	digit36 = temp % powN; // (0 ~ N^2 - 1)
			temp /= powN;
			
			// (0 ~ N^2 - 1) => (0~N-1, 0~N-1)
			int x = digit36 / N;
			int y = digit36 % N;
			
			if (map[x][y] != 'X')
			{
				flag = false; // X가 아니면 장애물을 세울 수 없다.
				break ;
			}
			tempMap[x][y] = 'O';
		}
		if (bfs(N, tempMap))
		{
			cout << "YES";
			return (0);
		}
		// bfs과정 중 비우지 못한 요소를 삭제
		while (!q.empty())
			q.pop();
	}
	cout << "NO";
}
