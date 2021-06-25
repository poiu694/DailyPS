#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1987654321;

vector<pair<int, int>> tree; // index - min&max
vector<int> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

pair<int, int> init(int node, int L, int R)
{
    if (L == R)
    {
        tree[node].first = list[L];
        tree[node].second = list[L];
        return tree[node];
    }

    int mid = (L + R) / 2;
    pair<int, int> left = init(2 * node, L, mid);
    pair<int, int> right = init(2 * node + 1, mid + 1, R);

    tree[node].first = min(left.first, right.first);
    tree[node].second = max(left.second, right.second);
    return tree[node];
}

pair<int, int> query(int L, int R, int node, int S, int E)
{
    if (L > E || R < S)
    {
        return {MAX, -MAX};
    }

    if (L <= S && E <= R)
    {
        return tree[node];
    }

    int mid = (S + E) / 2;
    pair<int, int> left = query(L, R, 2 * node, S, mid);
    pair<int, int> right = query(L, R, 2 * node + 1, mid + 1, E);

    return {min(left.first, right.first), max(left.second, right.second)};
}

void solve()
{
    int N, M;
    cin >> N >> M;

    list.resize(N + 1);
    int h = ceil(log2(N));
    tree.resize(1 << (h + 1));

    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    init(1, 0, N - 1);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;

        cout << query(a - 1, b - 1, 1, 0, N - 1).first << " " << query(a - 1, b - 1, 1, 0, N - 1).second << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}