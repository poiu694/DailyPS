#include <bitset>

bitset<100> bs(num);
string s = bs.to_string();
s = s.substr(s.find('1'));
cout << s << "\n";