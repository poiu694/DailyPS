#include <iostream>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// HD:HS, SD:SH 이 주어진 상태에서 각각에 x,y를 곱했을 때
// HD*x+SD*y>HS*x
// HD*x+SD*y>SH*y
// 우선 HD>HS면 y=0 대입 시 조건이 성립하고, SD>SH면 x=0 대입시 조건이 성립하므로 이 경우 무조건 갓을 만들 수 있다.
 
// 즉, HD<=HS, SD<=SH인 경우만 생각하면 된다.
// 넘겨서 정리하면 (HS-HD)*x<SD*y와 (SH-SD)*y<HD*x 가 성립하면 된다. x,y는 어떤 실수이면 되므로
// (HS-HD)*(SH-SD)<SD*HD가 성립하면 갓을 만들 수 있다.

bool is_god(int a, int b, int c, int d){
    if(a > b || c > d){
        return true;
    }

    if((b-a)*(d-c) < (c*a)){
        return true;
    }

    return false;
}

void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        if (is_god(c, d, e, f))
        {
            cout << "GOD" << '\n';
        }
        else
        {
            cout << "KDH" << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}