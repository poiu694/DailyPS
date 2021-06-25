#include <iostream>
#include <cmath>
#include <vector>
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

    vector<int> list;
    vector<char> op;

    stack<int> st;
    for(int i=0; i<target.length(); i++){
        if('0'<= target[i] && target[i] <= '9'){
            st.push(target[i] - '0');
        }else{
            int sum = 0, p = 0;

            while (!st.empty()) {
                sum += st.top() * pow(10, p);
                st.pop(); 
                p++;
            }
            list.push_back(sum);
            op.push_back(target[i]);
        }
    }
}

int main(){
    fastIO();
    solve();
}