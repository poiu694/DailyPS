#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValidPair(string target)
{
    stack<char> st;

    for (char ch : target)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;

            if (ch == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (ch == ')' && st.top() != '(')
                return false;

            if (ch == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (ch == '}' && st.top() != '{')
                return false;

            if (ch == ']' && st.top() == '[')
            {
                st.pop();
            }
            else if (ch == ']' && st.top() != '[')
                return false;
        }
    }
    if (!st.empty())
        return false;
    return true;
}

int solution(string s)
{
    int answer = 0;

    string target = s;
    for (int i = 0; i < s.length(); i++)
    {
        target += target[0];
        for (int i = 0; i < s.length(); i++)
            target[i] = target[i + 1];
        target.resize(s.length());

        if (isValidPair(target))
            answer++;
    }
    return answer;
}