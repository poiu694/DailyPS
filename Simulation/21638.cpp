#include <iostream>

using namespace std;

int main(void)
{
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  if (c < 0 && d >= 10)
  {
    cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
  }
  else if (a > c)
  {
    cout << "MCHS warns! Low temperature is expected tomorrow.";
  }
  else if (b < d)
  {
    cout << "MCHS warns! Strong wind is expected tomorrow.";
  }
  else
  {
    cout << "No message";
  }
}