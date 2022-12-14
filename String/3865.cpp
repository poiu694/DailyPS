#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

vector<string>	splitByDelimiter(string target, char delimiter)
{
	vector<string>	list;
	stringstream	ss(target);
	string	temp;

	while (getline(ss, temp, delimiter))
	{
		list.push_back(temp);
	}
	return (list);
}

int	main(void)
{
	int	T;
	int	targetIndex;
	bool	flag;
	string	target;
	vector<string>	splitListByColonList[101];
	vector<string>	splitListByCommaList[101];

	while (cin >> T)
	{
		if (T == 0)
			break ;
		for (int i=0; i<=100; i++)
		{
			splitListByColonList[i].clear();
			splitListByCommaList[i].clear();
		}

		for (int i=0; i<T; i++)
		{
			cin >> target;
			splitListByColonList[i] = splitByDelimiter(target, ':');
			splitListByCommaList[i] = splitByDelimiter(splitListByColonList[i][1], ',');
		}
			
		for (int i=0; i<T; i++)
		{
			flag = true;
			for (string str: splitListByCommaList[i])
			{
				for (int j=i+1; j<T; j++)
				{
					if (str.find(splitListByColonList[j][0]) != string::npos)
					{
						cout << i << " " << str << " " << splitListByColonList[j][0] << "\n";
						flag = false;
						break ;
					}
				}
			}
			if (flag)
			{
				targetIndex = i;
				break ;
			}
		}
		cout << splitListByCommaList[targetIndex].size() << '\n';
	}
}
