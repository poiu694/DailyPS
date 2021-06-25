#include <iostream>
#include <queue>
using namespace std;

/*
void _push(int value) {
    values[rear++] = value;
}

bool _empty() {
    if (rear == fIDX) {
        return true;
    }
    else {
        return false;
    }
}

void _pop() {
    if (!empty() && fIDX < rear) {
        cout << values[fIDX] << '\n';
        fIDX++;
    }
    else {
        cout << "-1" << endl;
    }
}


void _size() {
    cout << (rear - fIDX + MAX) % MAX << '\n';
}

void _back() {
    cout << values[rear-1] << '\n';
}

void _front() {
    cout << values[fIDX] << '\n';
}
*/
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    queue<int> q;
    int N;

    cin >> N;
    while (N--)
    {
        string str;
        int num;
        cin >> str;
        if (str == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (str == "front")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        else if (str == "back")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
        else if (str == "pop")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }
        else if (str == "size")
        {
            cout << q.size() << '\n';
        }
        else if (str == "empty")
        {
            if (q.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
    }
}

int main()
{
    fastIO();
    solve();
}