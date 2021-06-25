#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

vector<int> list;
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

    return tree[node] = (init(L, mid, 2 * node) * init(mid + 1, R, 2 * node + 1)) % MOD;
}

// A[X] = V
void update(int X, int V, int node, int S, int E)
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
    tree[node] = (tree[2 * node] * tree[2 * node + 1]) % MOD;
}

long long query(int L, int R, int node, int S, int E)
{
    if (L > E || R < S)
    {
        return 1;
    }

    if (L <= S && E <= R)
    {
        return tree[node];
    }

    int mid = (S + E) / 2;
    return (query(L, R, 2 * node, S, mid) * query(L, R, 2 * node + 1, mid + 1, E)) % MOD;
}

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;

    list.resize(N + 1);
    int h = ceil(log2(N));
    tree.resize(1 << (1 + h));

    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    init(0, N - 1, 1);

    int a, b, c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            update(b - 1, c, 1, 0, N - 1);
        }
        else
        {
            cout << query(b - 1, c - 1, 1, 0, N - 1) % MOD << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}