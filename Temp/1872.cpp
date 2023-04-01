#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

map<char, int>	roman_map(void)
{
	map<char, int>	m;

	m.insert({'I',1});
	m.insert({'V',5});
	m.insert({'X',10});
	m.insert({'L',50});
	m.insert({'C',100});
	m.insert({'D',500});
	m.insert({'M',1000});
	return (m);
}

string	get_only_roman(string target)
{
	string	ret;
	map<char, int>	m;

	ret = "";
	m = roman_map();
	transform(target.begin(), target.end(), target.begin(), ::toupper);
	for (int i=0; i<target.length(); i++)
	{
		if (m[target[i]])
			ret += target[i];
	}
	return (ret);
}

string	valid_roman_rule(string target)
{
	string	ret;
	string	roman;
	map<char, int>	m;
	int count[7] = {10000,1,3,1,3,1,3};
	
	ret = "";
	roman = "IVXLCDM";
	m = roman_map();
	for (int i=0; i<target.length(); i++)
	{
		if (i < target.length() - 1)
		{
			// 뒤에 오는 문자보다 작은 숫자일 수 있다.
			// 이런 경우는 앞에 문자를 무시해야 제일 큰 값이 나온다.
			if (m[target[i]] < m[target[i + 1]] && i != target.length() - 2)
				continue ;
		}
		ret += target[i];
		
	}
	return (ret);
}

long long	get_score(string target)
{
	long long	ret;
	map<char, int>	m;

	ret = 0;
	m = roman_map();
	cout << "T : " << target << '\n';
	for (int i=0; i<target.length(); i++)
	{
		if (i < target.length() - 1)
		{
			if (m[target[i]] < m[target[i + 1]])
			{
				// 마지막인 경우밖에 없다.
				ret += m[target[i + 1]] - m[target[i]];
				break ;
			}
		}
		ret += m[target[i]];
	}
	return (ret);
}

int	main(void)
{
	int	T;
	string	target;
	string	roman;

	cin >> T;
	cin.ignore();
	while (T--)
	{
		getline(cin, target);
		cout << "AA : " << target << '\n';
		roman = get_only_roman(target);
		cout << get_score(valid_roman_rule(roman)) << '\n';
	}
}
