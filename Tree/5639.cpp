#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void findPostOrderFromPreOrdrer(vector<int> &list, int lowwer, int upper, int &index)
{
    if (index == list.size())
        return;

    if (list[index] < lowwer || list[index] > upper)
        return;

    int node = list[index++];
    findPostOrderFromPreOrdrer(list, lowwer, node, index);
    findPostOrderFromPreOrdrer(list, node, upper, index);
    cout << node << '\n';
}

void solve()
{
    vector<int> list;
    int temp;
    while (cin >> temp)
    {
        list.push_back(temp);
    }
    int index = 0;
    findPostOrderFromPreOrdrer(list, -1, 1e6 + 1, index);
}

int main()
{
    fastIO();
    solve();
}
