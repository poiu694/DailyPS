#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[201][201];
int parent[201];
vector<int> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int getParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    else
    {
        return parent[n] = getParent(parent[n]);
    }
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

void init()
{
    cin >> N >> M;

    // parent 초기화
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                unionParent(i, j);
            }
        }
    }

    int temp;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        list.push_back(temp);
    }
}

bool is_trip()
{
    bool flag = true;

    if (list[0] == list[M - 1])
    {
        return true;
    }

    int UnionParent = getParent(list[0]);
    for (int i = 1; i < list.size(); i++)
    {
        if (UnionParent != parent[list[i]])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void solve()
{
    if (is_trip())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    fastIO();
    init();
    solve();
}