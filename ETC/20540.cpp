#include <iostream>

using namespace std;

int main(){
    char my[4];
    char his[4];

    cin >> my; // input the My MBTI

    if(my[0] == 'E'){
        his[0] = 'I';
    }else{
        his[0] = 'E';
    }

    if(my[1] == 'S'){
        his[1] = 'N';
    }else{
        his[1] = 'S';
    }

    if(my[2] == 'F'){
        his[2] = 'T';
    }else{
        his[2] = 'F';
    }

    if(my[3] == 'J'){
        his[3] = 'P';
    }else{
        his[3] = 'J';
    }

    cout << his[0] << his[1] << his[2] << his[3];

    return 0;
}