#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int stringToIntTime(string time)
{
    int sum = 0;
    sum += stoi(time.substr(11, 2)) * 3600 * 1000;
    sum += stoi(time.substr(14, 2)) * 60 * 1000;
    sum += stoi(time.substr(17, 2)) * 1000;
    sum += stoi(time.substr(20, 3));

    return sum;
}

int getRunningTime(string time)
{
    time = time.substr(24);
    if (time.find(".") != string::npos)
    {
        int sIndex = time.find("s");
        int sum = 0;
        sum += stoi(time.substr(0, 1)) * 1000;
        sum += stoi(time.substr(2, sIndex - 2));
        return sum;
    }
    else
    {
        return stoi(time.substr(0, 1)) * 1000;
    }
}

pair<int, int> stringToTimeFormat(string time)
{
    int endTime = stringToIntTime(time);
    int runningTime = getRunningTime(time);

    int startTime = endTime - runningTime + 1;
    return {startTime, endTime};
}

int solution(vector<string> lines)
{
    vector<int> timeTable(24 * 3600 * 1000 + 3, 0);
    for (string line : lines)
    {
        auto tm = stringToTimeFormat(line);
        if (tm.first < 0)
        {
            for (int i = 0; i <= tm.second + 999; i++)
                timeTable[i]++;
            continue;
        }
        for (int i = tm.first; i <= tm.second + 999; i++)
        {
            if (i >= 86400000)
                break;
            timeTable[i]++;
        }
    }
    int answer = -1;
    for (int i = 0; i < 86400000; i++)
    {
        if (answer < timeTable[i])
            answer = timeTable[i];
    }

    return answer;
}