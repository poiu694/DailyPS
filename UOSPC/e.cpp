#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int findFox(string target)
{
    stack<char> st;

    int ret = 0;
    int cnt = 0;
    for (int i=0; i<target.length(); i++)
    {
        char now = target[i] == '(' ? ')' : '(';
        ret++;
        if (st.empty())
            st.push(now);
        else if (st.top() == '(' and now == ')')
        {
            cnt++;
            st.pop();
        }
        else
            st.push(now);   
    }
    if (st.size() != 0 and cnt != 0)
        ret -= cnt;
    return (ret - (st.size() / 2));
}

int findNu(string target)
{
    stack<char> st;

    int ret = 0;
    for (int i=0; i<target.length(); i++)
    {
        if (target[i] == '(')
            st.push(target[i]);
        else
        {
            if (st.empty())
            {
                ret+=2;
                st.push('(');
            }
            else if (st.top() == '(')
                st.pop();
            else
            {
                st.pop();
                ret += 2;
            }
        }
    }
    return (ret);
}

void    get_solution(void)
{
    int N;
    string  target;

    cin >> N >> target;
    cout << findFox(target) << '\n' << findNu(target);   
}

int main(void)
{
    fast_io();
    get_solution();
}
