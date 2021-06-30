#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> splitString(string target, char delimiter1, char delimiter2)
{
    vector<string> ret;
    stringstream ss(target);
    string stringbuffer1, stringbuffer2;

    while (getline(ss, stringbuffer1, delimiter1))
    {
        stringstream ss2(stringbuffer1);
        while (getline(ss2, stringbuffer2, delimiter2))
        {
            ret.push_back(stringbuffer2);
        }
    }

    return ret;
}