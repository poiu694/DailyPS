#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> list, NGE;
    stack<int> st;
    cin >> N;

    list.resize(N);
    NGE.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        NGE[i] = -1;
    }

    int index = N - 1;
    for (int i = 0; i < list.size(); i++)
    {
        while (!st.empty() && list[st.top()] < list[i])
        {
            NGE[st.top()] = list[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << NGE[i] << " ";
    }
}

int main()
{
    fastIO();
    solve();
}