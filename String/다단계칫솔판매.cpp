#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    map<string, int> m;
    map<string, string> parent;
    for (int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int money = amount[i] * 100;
        string now = seller[i];
        string next = "";
        while (next != "-")
        {
            next = parent[now];
            if (money < 10)
            {
                m[now] += money;
                break;
            }

            int giveMoney = money / 10;
            m[now] += (money - giveMoney);
            money = giveMoney;
            now = next;
        }
    }
    for (string person : enroll)
    {
        answer.push_back(m[person]);
    }
    return answer;
}