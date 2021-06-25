#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[5001][5001];
vector<int> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> N;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        list.push_back(temp);
    }
}

int pLCS()
{
    vector<int> rev = list;

    for (int i = 0; i < N; i++)
    {
        cout << rev[i] << " ";
    }
    return 0;
}

void solve()
{
    cout << list.size() - pLCS();
}

int main()
{
    fastIO();
    input();
}