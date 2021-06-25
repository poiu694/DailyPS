#include <iostream>
#include <cstring>

using namespace std;

string num;
string one = "132", two = "211", three="232";
int L, R, time;
int cnt1, cnt2, cnt3;

void fastIO(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

void time_flow(string str, int cnt){
    if(time == cnt){
        string temp = str.substr(L, R);

        for(int i=0; i<temp.length(); i++){
            if(temp[i] == '1'){
                cnt1++;
            }else if(temp[i] == '2'){
                cnt2++;
            }else{
                cnt3++;
            }
        }
        cout << cnt1 << " " << cnt2 << " " << cnt3;
    }

    for(int i=0; i<str.length(); i+=3){
        if(str[i] == '1'){
            str.replace(i, 1, one);
        }else if(str[i] == '2'){
            str.replace(i, 1, two);
        }else{
            str.replace(i, 1, three);
        }
    }

    time_flow(str, cnt + 1);
}

void solve(){
    cin >> num >> L >> R >> time;

    time_flow(num, 0);
}

int main(){
    fastIO();
    solve();
}