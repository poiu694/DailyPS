#include <iostream>
#include <vector>

using namespace std;

int	parent[51];

int	find_parent(int node)
{
	if (node == parent[node])
	{
		return (node);
	}
	return (parent[node] = find_parent(parent[node]));
}

void	union_graph(int node1, int node2)
{
	node1 = find_parent(node1);
	node2 = find_parent(node2);
	parent[node2] = node1;
}

bool	is_same_parent(int node1, int node2)
{
	return (find_parent(node1) == find_parent(node2));
}

bool	has_true_person_in_party(vector<int> partyList, vector<int> trueList)
{
	int	node;

	for (int i=0; i<partyList.size(); i++)
	{
		node = partyList[i];
		for (int j=0; j<trueList.size(); j++)
		{
			if (is_same_parent(node, trueList[j]))
			{
				return (false);
			}
		}
	}
	return (true);
}

int	main(void)
{
	int	n, m, t;
	int	partySize;
	int	answer;
	vector<int>	list[51];
	vector<int>	trueList;

	cin >> n >> m >> t;
	for (int i=1; i<=n; i++)
	{
		parent[i] = i;
	}
	trueList.resize(t);
	answer = 0;
	for (int i=0; i<t; i++)
	{
		cin >> trueList[i];
	}
	for (int i=0; i<m; i++)
	{
		cin >> partySize;
		list[i].resize(partySize);
		for (int j=0; j<partySize; j++)
		{
			cin >> list[i][j];
			if (j != 0)
			{
				union_graph(list[i][0], list[i][j]);
			}
		}
	}
	for (int i=0; i<m; i++)
	{
		answer += has_true_person_in_party(list[i], trueList);
	}
	cout << answer;
}
