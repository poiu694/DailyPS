#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> list;
vector<long long> tree;
vector<long long> lazy; // lazy segment tree

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long init(int node, int L, int R)
{
    if (L == R)
    {
        tree[node] = list[L];
        return tree[node];
    }

    int mid = (L + R) / 2;
    return tree[node] = init(2 * node, L, mid) + init(2 * node + 1, mid + 1, R);
}

void lazyUpdate(int node, int L, int R)
{
    if (lazy[node] != 0)
    {
        tree[node] += (R - L + 1) * lazy[node]; // leaf를 급하게 바꾸지 않는다.

        if (L != R)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// a[L ... R] = a[L ... R] + V
void update(int L, int R, long long V, int node, int S, int E)
{
    lazyUpdate(node, S, E);

    if (R < S || E < L)
    {
        return;
    }

    if (L <= S && E <= R)
    {
        tree[node] += (E - S + 1) * V; // tree를 급하게 바꾸지 않는다.

        // leaf 노드가 아닐 경우 자식들이 나중에 V만큼 업데이트 해야 함을 알린다.
        if (S != E)
        {
            lazy[2 * node] += V;
            lazy[2 * node + 1] += V;
        }
        return;
    }

    int mid = (S + E) / 2;
    update(L, R, V, 2 * node, S, mid);
    update(L, R, V, 2 * node + 1, mid + 1, E);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int L, int R, int node, int S, int E)
{
    lazyUpdate(node, S, E);
    if (R < S || E < L)
    {
        return 0;
    }

    if (L <= S && E <= R)
    {
        return tree[node];
    }

    int mid = (S + E) / 2;

    return query(L, R, 2 * node, S, mid) + query(L, R, 2 * node + 1, mid + 1, E);
}

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;

    int h = ceil(log2(N));
    list.resize(N + 1);
    tree.resize(1 << (1 + h));
    lazy.resize(1 << (1 + h));

    for (int i = 1; i <= N; i++)
    {
        cin >> list[i];
    }

    init(1, 1, N);

    long long a, b, c, d;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b >> c >> d;
            update(b, c, d, 1, 1, N);
        }
        else
        {
            cin >> b >> c;
            cout << query(b, c, 1, 1, N) << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}