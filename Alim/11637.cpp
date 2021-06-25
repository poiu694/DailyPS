#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(int a, int b)
{
    return a > b;
}

void init()
{
    list.clear();
    cin >> N;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        list.push_back(temp);
    }
}

bool is_winner()
{
    vector<int> a = list;

    sort(a.begin(), a.end(), cmp);

    if (a[0] == a[1])
    {
        return false;
    }
    return true;
}

void who_winner()
{
    int index = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (list[index] < list[i])
        {
            index = i;
        }
        sum += list[i];
    }

    if (list[index] > sum / 2)
    {
        cout << "majority winner " << index + 1 << '\n';
    }
    else
    {
        cout << "minority winner " << index + 1 << '\n';
    }
}

void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        init();
        if (!is_winner())
        {
            cout << "no winner" << '\n';
            continue;
        }
        else
        {
            who_winner();
        }
    }
}

int main()
{
    fastIO();
    solve();
}