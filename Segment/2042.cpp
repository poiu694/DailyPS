#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> list;
vector<long long> tree;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long init(int L, int R, int node)
{
    if (L == R)
    {
        return tree[node] = list[L];
    }

    int mid = (L + R) / 2;
    return tree[node] = init(L, mid, 2 * node) + init(mid + 1, R, 2 * node + 1);
}

// A[X] = V
void update(int X, long long V, int node, int S, int E)
{
    if (S > X || E < X)
    {
        return;
    }

    if (S == E)
    {
        tree[node] = V;
        return;
    }

    int mid = (S + E) / 2;
    update(X, V, 2 * node, S, mid);
    update(X, V, 2 * node + 1, mid + 1, E);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long cal(int L, int R, int node, int S, int E)
{
    // 범위 초과
    if (R < S || E < L)
    {
        return 0;
    }

    if (L <= S && E <= R)
    {
        return tree[node];
    }

    int mid = (S + E) / 2;
    return cal(L, R, 2 * node, S, mid) + cal(L, R, 2 * node + 1, mid + 1, E);
}

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;

    list.resize(N + 1);
    int h = ceil(log2(N));
    tree.resize(1 << (h + 1));
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }
    init(0, N - 1, 1);

    int a, b;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b;

        if (a == 1)
        {
            long long c;
            cin >> c;
            update(b - 1, c, 1, 0, N - 1);
        }
        else
        {
            int c;
            cin >> c;
            cout << cal(b - 1, c - 1, 1, 0, N - 1) << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}
