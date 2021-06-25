#include <iostream>
#include <list>

using namespace std;



void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    list<char> arr;
    list<char>::iterator it;
    char op, temp;
    int M;  

    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++){
        arr.push_back(str[i]);
    }
    it = arr.end();

    cin >> M;    
    for(int i=0; i<M; i++){
        cin >> op;

        if(op == 'P'){
            cin >> temp;
            arr.insert(it, temp);
        }else if(op == 'L'){
            if(it != arr.begin()){
                it--;
            }
        }else if(op == 'D'){
            if(it != arr.end()){
                it++;
            }
        }else if(op == 'B'){
            if(it != arr.begin()){
                it = arr.erase(--it);
            }
        }
    }
}