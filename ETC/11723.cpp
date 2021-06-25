#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int M;
vector<bool> list(21, false);

void check(int n){
    if(list[n]){
    	cout << "1" << "\n";
    }else{
    	cout << "0" << "\n";
    }
}

void toggle(int n){
    if(list[n]){
    	list[n] = false;
    }else{
    	list[n] = true;
    }
}

void all(){
    for(int i=1; i<=20; i++){
    	list[i] = true;
    }
}

void empty(){
   for(int i=1; i<=20; i++){
    	list[i] = false;
    }
}

void solve(string str){
    int num;

    if(str == "add"){
        cin >> num;
        list[n] = true;
    }else if(str == "remove"){
        cin >> num;
        list[n] = false;
    }else if(str == "check"){
        cin >> num;
        check(num);
    }else if(str == "toggle"){
        cin >> num;
        toggle(num);
    }else if(str == "all"){
        all();
    }else if(str == "empty"){
        empty();
    }

}

void input(){
    cin >> M;

    int num;
    string str;

    for(int i=0; i<M; i++){
        cin >> str;
        solve(str);
    }
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
}
