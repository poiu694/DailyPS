using namespace std;

long long solution(int price, int money, int count)
{
    long long requiredMoney = ((long long)count * (price + (price * count))) / 2;
    return money < requiredMoney ? requiredMoney - money : 0;
}