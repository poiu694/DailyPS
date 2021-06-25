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

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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

int getParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    else
    {
        return parent[n] = getParent(n);
    }
}

void unionParent(int a, int b)
{
    int a = getParent(a);
    int b = getParent(b);

    parent[b] = a;
}

bool is_trip()
{
    bool flag = true;

    int parent = getParent(list[0]);
    for (int i = 0; i < list.size(); i++)
    {
        if (parent != list[i])
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
    input();
    solve();
}