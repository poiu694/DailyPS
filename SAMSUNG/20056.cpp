#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct FB
{
    int r;
    int c;
    int m;
    int s;
    int d;
};

int N, M, K;
int map[51][51];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<FB> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    cin >> N >> M >> K;
    list.resize(M);

    for (int i = 0; i < M; i++)
    {
        cin >> list[i].r >> list[i].c >>
            list[i].m >> list[i].s >> list[i].d;
    }

    // K번만큼 이동
    while (K--)
    {
        memset(map, 0, sizeof(map));
        // 움직이자
        for (auto fire : list)
        {
            fire.r = fire.r + (fire.s * dr[fire.d]);
            fire.c = fire.c + (fire.s * dr[fire.d]);

            if (fire.c > N)
            {
                fire.c = fire.c % N;
                ;
            }
            else if (fire.c <= 0)
            {
                while (fire.c > 0)
                {
                    fire.c = N + fire.c;
                }
            }

            if (fire.r > N)
            {
                fire.r = fire.c % N;
            }
            else if (fire.r <= 0)
            {
                while (fire.r > 0)
                {
                    fire.r = N + fire.r;
                }
            }

            map[fire.r][fire.c]++;
        }

        // 확인하자
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] > 1)
                { // 합쳐진 파이어볼
                }
            }
        }
    }

    for (auto a : list)
    {
        cout << a.r << " " << a.c << " " << a.m << " " << a.s << " " << a.d << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}