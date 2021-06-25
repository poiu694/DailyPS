#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isCan(vector<string> birds[101], vector<string> targetList, int N)
{
    int birdIndex[103] = {
        0,
    };
    for (int i = 0; i < targetList.size(); i++)
    {
        bool flag = false;
        for (int j = 1; j <= N; j++)
        {
            if (birds[j].size() <= birdIndex[j])
            {
                continue;
            }

            if (targetList[i] == birds[j][birdIndex[j]])
            {
                birdIndex[j]++;
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            return false;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (birds[i].size() != birdIndex[i])
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int N;
    vector<string> birds[103];
    vector<string> targetList;
    string temp, target;
    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        getline(cin, temp, '\n');

        string words = "";
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == ' ')
            {
                birds[i].push_back(words);
                words = "";
            }
            else
            {
                words += temp[j];
            }
        }
        birds[i].push_back(words);
    }

    getline(cin, target, '\n');
    temp = "";
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] == ' ')
        {
            targetList.push_back(temp);
            temp = "";
        }
        else
        {
            temp += target[i];
        }
    }
    targetList.push_back(temp);

    if (isCan(birds, targetList, N))
    {
        cout << "Possible";
    }
    else
    {
        cout << "Impossible";
    }
}

int main()
{
    fastIO();
    solve();
}