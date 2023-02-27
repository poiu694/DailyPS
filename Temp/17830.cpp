#include <iostream>
#include<cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include<deque>
using namespace std;
 
int maxstring(int n,string &s)//자릿수 최대로 만드는 함수
{
    int oneidx = -1;
    int cnt1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (oneidx == -1&&(s[i]=='1'||s[i]=='?'))
        {
            oneidx = s.size() - i;
            cnt1++;
            continue;
        }
        if (s[i] == '1' || s[i] == '?')//?표는 무조껀 1로바꾼다고 생각하면됨
            cnt1++;
    }
    if (cnt1 == 0)
        return 1;//1이아무것도 없으니 그냥 곱해봤자 0이될테니 사이즈를 출력하는거니까 1
    else if (cnt1 == 1)//1이 한개밖에없다는 뜻임 결국 뒤에 0만채우는꼴
        return n + oneidx - 1;
    return n+oneidx;//여긴 cnt1 이 2개이상이라는뜻이지만 1의 맨앞자리 자릿수와 더해주면 끝
}
 
int minstring(int n, string &s)//자릿수 최대로 만드는 함수
{
    int oneidx = -1;
    int cnt1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (oneidx == -1 && (s[i] == '1' ))
        {
            oneidx = s.size() - i;
            cnt1++;
            continue;
        }
        if (s[i] == '1')//?표는 필요없음 전부 0이라고 생각하면됨
            cnt1++;
    }
    if (cnt1 == 0)
        return 1;//1이아무것도 없으니 그냥 곱해봤자 0이될테니
    else if (cnt1 == 1)//1이 한개밖에없다는 뜻임 결국 뒤에 0만채우는꼴
        return n + oneidx - 1;
    return n + oneidx;//여긴 cnt1 이 2개이상이라는뜻이지만 1의 맨앞자리 자릿수와 더해주면 끝
}
 
 
void solve(int n, string &s)
{
    cout << maxstring(n, s) <<" "<<minstring(n,s)<<"\n";
}
 
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        string s;
        cin>>n >> s;
        solve(n, s);
    }
 
}