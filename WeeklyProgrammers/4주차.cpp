#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> splitToList(string input)
{
    vector<string> ret;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ' '))
    {
        ret.push_back(temp);
    }

    return ret;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "zzz";

    int maxSum = -1;
    for (string str : table)
    {
        vector<string> list = splitToList(str);
        int sum = 0;

        for (int i = 0; i < languages.size(); i++)
        {
            int index = find(list.begin(), list.end(), languages[i]) - list.begin();

            if (index != list.size())
            {
                sum += (6 - index) * preference[i];
            }
        }

        if (maxSum == sum && answer > list[0])
        {
            maxSum = sum;
            answer = list[0];
        }
        else if (maxSum < sum)
        {
            maxSum = sum;
            answer = list[0];
        }
    }

    return answer;
}