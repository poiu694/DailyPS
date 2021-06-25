#include <iostream>
#include <cstring>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void solve(){
    string temp;
    
    while(true){

        getline(cin, temp);

        int smallLetter = 0;
        int largeLetter = 0;
        int number = 0;
        int blank = 0;

        for(char ch : temp){
            //소문자
            if(ch>='a'&&ch<='z'){
                smallLetter++;
            }
            //대문자
            else if(ch>='A'&&ch<='Z'){
                largeLetter++;
            }
            //숫자
            else if(ch>='0'&&ch<='9'){
                number++;
            }
            //공백
            else if(ch==32){
                blank++;
            }
            else{
                cout << "Something wrong!";
            }
        }

        cout << smallLetter << ' ' << largeLetter << ' ' << number <<' '<<blank<<' '<<'\n';
    }
}

int main(){
    init();
    solve();
}