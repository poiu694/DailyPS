#include <iostream>
#include <string>

using namespace std;

int N, K;
string dp[101][101];

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> N >> K;
}

// nCk = n-1Ck + n-1Ck-1
string bigAdd(string N, string K)
{
    long long sum = 0;
    string result = "";

    while (!N.empty() || !K.empty() || sum)
    {
        if (!N.empty())
        {
            sum += N.back() - '0';
            N.pop_back();
        }
        if (!K.empty())
        {
            sum += K.back() - '0';
            K.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string nCk(int N, int K)
{
    if (N == K || K == 0)
    {
        return "1";
    }

    string &result = dp[N][K];
    if (result != "")
    {
        return result;
    }

    result = bigAdd(nCk(N - 1, K - 1), nCk(N - 1, K));
    return result;
}

void solve()
{
    cout << nCk(N, K);
}

int main()
{
    init();
    input();
    solve();
}

string bigAdd(string N, string K)
{
    long long sum = 0;
    string result = "";

    while (!N.empty() || !K.empty() || sum)
    {
        if (!N.empty())
        {
            sum += N.back() - '0';
            N.pop_back();
        }
        if (!K.empty())
        {
            sum += K.back() - '0';
            K.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string bigSub(string a, string b)
{
    string result = "";

    int a_len = a.length(), b_len = b.length();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;

    for (int i = 0; i < b_len; i++)
    {
        int sub = ((a[i] - '0') - (b[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    for (int i = b_len; i < a_len; i++)
    {
        int sub = ((a[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}
