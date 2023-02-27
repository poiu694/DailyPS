// https://leetcode.com/problems/multiply-strings/#
string multiply(string num1, string num2)
{
	int	len1, len2;
	int	p1, p2, mul, sum;
	string	result;

	len1 = num1.length();
	len2 = num2.length();
	vector<int>	list(len1 + len2);
	for (int i=len1-1; i>=0; i--)
	{
		for (int j=len2-1; j>=0; j--)
		{
			p1 = i + j;
			p2 = i + j + 1;
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + list[p2];

			list[p1] += sum / 10;
			list[p2] = sum % 10;
		}
	}
	result = "";
	for (int i=0; i<list.size(); i++)
	{
		result += to_string(list[i]);
	}
	return (result);
}