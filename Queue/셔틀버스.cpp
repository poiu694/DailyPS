#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int timeToInt(string time)
{
    int sum = 0;
    sum += stoi(time.substr(0, 2)) * 60;
    sum += stoi(time.substr(3, 2));
    return sum;
}

string intToTimeFormat(int time)
{
    string hour = to_string(time / 60);
    string minute = to_string(time % 60);
    if (hour.length() == 1)
        hour = "0" + hour;
    if (minute.length() == 1)
        minute = "0" + minute;
    string ret = hour + ":" + minute;
    return ret;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    priority_queue<int> pq;
    for (string time : timetable)
    {
        pq.push(-timeToInt(time));
    }

    int busTime = 9 * 60;
    int peopleCnt = 0;
    int busCnt = 1;
    int ansTime = -1;
    while (!pq.empty())
    {
        int now = -pq.top();
        pq.pop();

        if (busTime >= now)
        {
            peopleCnt++;
            if (peopleCnt == m)
            {
                if (busCnt != n)
                {
                    peopleCnt = 0;
                    busCnt++;
                    busTime += t;
                }
                else
                {
                    ansTime = now - 1;
                    break;
                }
            }
        }
        else
        {
            if (busCnt != n)
            {
                while (true)
                {
                    busTime += t;
                    busCnt++;
                    if (now <= busTime)
                    {
                        break;
                    }

                    if (busCnt == n)
                        break;
                }
                peopleCnt = 1;

                if (peopleCnt == m and busCnt == n)
                {
                    ansTime = now - 1;
                    break;
                }
            }
            else
            {
                ansTime = now - 1;
                break;
            }
        }
    }

    if (ansTime > busTime or ansTime == -1)
    {
        ansTime = (60 * 9) + t * (n - 1);
    }
    string answer = intToTimeFormat(ansTime);
    return answer;
}