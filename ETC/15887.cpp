#include <iostream>
#include <vector>

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
    vector<int> list(N + 2);
    vector<pair<int, int>> answer(1e6 + 5);
    for (int i = 1; i <= N; i++)
    {
        cin >> list[i];
    }

    int index = 0;
    // Bubble Sort
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                answer[index].first = j;
                answer[index].second = j + 1;

                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;

                index++;
            }
        }
    }

    cout << index << '\n';
    for (int i = 0; i < index; i++)
    {
        cout << answer[i].first << " " << answer[i].second << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}