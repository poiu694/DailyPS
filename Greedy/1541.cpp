#include <iostream>
#include <string>

using namespace std;

int index = 0;
int answer;
string str;
int num[] ={0};
int op[] ={0}; // op[i] == 0 -> '+', op[i] == 1 -> '-'

void solve(){
    string sol = "";
	
    answer = num[0];
    for(int i=1; i<index+1; i++){
        answer = answer - num[i];
    }

    cout << answer;
}

void input(){
    cin >> str;

    int temp = 0; // 배열을 잘라주기 위한 변수(정수)

    // 입력
    for(int i=0; i<str.length(); i++){
        if(str[i] == '+'){
            op[index] = 0;
            num[index++] = stoi(str.substr(temp, i-temp));
            temp = i + 1;
        }else if(str[i] == '-'){
            op[index] = 1;
            num[index++] = stoi(str.substr(temp, i-temp));
            temp = i + 1;
        }
    }
    // 마지막 정수
    num[index] = stoi(str.substr(temp, str.length()-temp));

}

int main(){
    input();
    solve();
}