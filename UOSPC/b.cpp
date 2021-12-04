#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void    get_solution(void)
{
    int N, M;
    string temp;
    char board[101][101];

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        cin >> temp;
        for (int j=0; j<M; j++)
            board[i][j] = temp[j];
    }
    int cnt = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (board[i][j] == 'C')
            {
                bool flag = true;
                if (i - 1 >= 0 and board[i - 1][j] == 'P')
                    flag = false;
                if (i + 1 <= N and board[i + 1][j] == 'P')
                    flag = false;
                if (j - 1 >= 0 and board[i][j - 1] == 'P')
                    flag = false;
                if (j + 1 <= M and board[i][j + 1] == 'P')
                    flag = false;
                if (flag)
                    cnt++;
            }
        }
    }
    cout << cnt;
}

int main(void)
{
    fast_io();
    get_solution();
}
