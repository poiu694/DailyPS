#include <iostream>
#include <cstring>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N;
    cin >> N;

    int ans = 10001; // ans Max : 200 * 5 * 3 : 3000
    int map[11][11];
    bool visited[11][11];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int line = N - 2;
    int linePow = line * line;
    for (int brute = 0; brute < (linePow * linePow * linePow); brute++)
    {
        memset(visited, false, sizeof(visited)); // 경우마다 방문여부 초기화
        int temp = brute;
        bool flag = true;

        // N : 6 16진법으로 변환, 꽃의 씨앗은 (1,1) ~ (4,4)가 가능하고, 16개의 경우의수
        // N : 10 64진법으로 변환, 꽃의 씨앗은 (1,1) ~ (8,8)가 가능하고, 64개의 경우의수다.
        for (int i = 0; i < 3; i++)
        {
            int digitN = temp % linePow;
            temp /= linePow;

            // 64진법을 x,y좌표로 환산
            int x = (digitN / line) + 1;
            int y = (digitN % line) + 1;

            if (x >= N || y >= N)
            {
                flag = false;
                break;
            }

            // 겹치면 불가능
            if (visited[x][y] || visited[x + 1][y] ||
                visited[x - 1][y] || visited[x][y + 1] || visited[x][y - 1])
            {
                flag = false;
                break;
            }
            visited[x][y] = true;
            visited[x + 1][y] = true;
            visited[x - 1][y] = true;
            visited[x][y + 1] = true;
            visited[x][y - 1] = true;
        }

        if (flag)
        {
            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (visited[i][j])
                    {
                        sum += map[i][j];
                    }
                }
            }
            ans = ans < sum ? ans : sum;
        }
    }

    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
