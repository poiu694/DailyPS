#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
using psi=pair<string, int>;

int minutesFromHHMM(string HHMM)
{
    int result;
    
    result = 0;
    result += stoi(HHMM.substr(0, 2)) * 60;
    result += stoi(HHMM.substr(3, 5));
    return (result);
}

bool    compare(const vector<string> &a, const vector<string> &b)
{
    return (minutesFromHHMM(a[1]) < minutesFromHHMM(b[1]));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    deque<psi>  wait;

    sort(plans.begin(), plans.end(), compare); // 시간순 정렬
    int time = minutesFromHHMM(plans[0][1]);
    for (int i=0; i<plans.size(); i++)
    {
        auto plan = plans[i];
        
        if (i < plans.size() - 1)
        {
            int nextStartTime = minutesFromHHMM(plans[i + 1][1]);
            int timeDiff = nextStartTime - time;
            
            if (timeDiff < stoi(plan[2]))
            {
                // C3
                wait.push_back({ plan[0], stoi(plan[2]) - timeDiff });
            }
            else
            {
                timeDiff -= stoi(plan[2]);
                answer.push_back(plan[0]);
                while (!wait.empty() && timeDiff >= wait.back().second)
                {
                    // C1
                    timeDiff -= wait.back().second;
                    answer.push_back(wait.back().first);
                    wait.pop_back();
                }
                if (!wait.empty() && timeDiff > 0)
                {
                    string t1 = wait.back().first;
                    int t2 = wait.back().second - timeDiff;
                    wait.pop_back();
                    wait.push_back({ t1, t2 });
                }
            }
            time = nextStartTime;    
        }
        else
        {
            answer.push_back(plan[0]);
        }
    }
    while (!wait.empty())
    {
        answer.push_back(wait.back().first);
        wait.pop_back();
    }
    return answer;
}