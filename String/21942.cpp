#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dayToMinute(int day, int hour, int minute)
{
    int sum = 0;

    sum += day * 24 * 60;
    sum += hour * 60;
    sum += minute;
    return sum;
}

int dateToDay(string date)
{
    int sum = 0;

    // stoi(substr(n,k))`s TimeComplexity : O(N*k)
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (month == 2)
        sum += 31;
    else if (month == 3)
        sum += 59;
    else if (month == 4)
        sum += 90;
    else if (month == 5)
        sum += 120;
    else if (month == 6)
        sum += 151;
    else if (month == 7)
        sum += 181;
    else if (month == 8)
        sum += 212;
    else if (month == 9)
        sum += 243;
    else if (month == 10)
        sum += 273;
    else if (month == 11)
        sum += 304;
    else if (month == 12)
        sum += 334;

    sum += day;
    return sum;
}

bool cmp(const pair<string, pair<string, long long>> &a, const pair<string, pair<string, long long>> &b)
{
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
        {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }

    return a.first < b.first;
}

void solve()
{
    int N, fine, limitTime;
    string temp;
    cin >> N >> temp >> fine;
    limitTime = dayToMinute(stoi(temp.substr(0, 3)), stoi(temp.substr(4, 2)), stoi(temp.substr(7, 2)));

    vector<pair<string, pair<string, long long>>> list;
    for (int i = 0; i < N; i++)
    { // O(N logN)
        string date, t, book, name;
        cin >> date >> t >> book >> name;

        long long time = dayToMinute(dateToDay(date), 0, 0) + stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        list.push_back({name, {book, time}});
    }
    sort(list.begin(), list.end(), cmp);

    map<string, long long> ans;
    string pastName = "";
    string pastBook = "";
    long long pastTime = -1;
    for (auto now : list)
    {
        string nowName = now.first;
        string nowBook = now.second.first;
        long long nowTime = now.second.second;

        if (pastName == nowName && pastBook == nowBook)
        {
            long long diffDate = nowTime - pastTime;

            if (diffDate > limitTime)
            {
                ans[nowName] += (diffDate - limitTime) * fine;
            }
        }

        pastName = nowName;
        pastBook = nowBook;
        pastTime = nowTime;
    }

    if (ans.size() == 0)
        cout << -1;
    else
    {
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            cout << it->first << " " << it->second << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}
