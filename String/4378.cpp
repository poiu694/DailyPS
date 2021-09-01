#include <iostream>
#include <string>
using namespace std;

int main()
{
  string keyboard("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
  char c;
  while (1)
  {
    cin.get(c);
    if (cin.eof())
    {
      return 0;
    }

    if (c == ' ' || c == '\n')
      cout << c;
    else
      cout << keyboard[keyboard.find(c) - 1];
  }
}