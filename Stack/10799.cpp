#include <iostream>
#include <stack>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    string target;
    cin >> target;

    stack<char> st;
    int answer = 0;
    int temp = 0;
    for(int i=0; i<target.length(); i++){
        if(target[i] == '('){
            temp++;
            st.push(target[i]);
        }else{
            if(target[i-1] == '('){
                temp--;
                answer += temp;
                st.pop();
            }else{
                temp--;
                st.pop(target[i]);
            }
        }
    }
}

int main(){
    fastIO();
    solve();
}