#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	long c= a + b;
	string str=to_string(c);
	int count = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (count % 3 == 0 && count >= 3&&str[i]!='-')
			str=str.insert(i+1, ",");
		count++;
	}
	cout << str << endl;
	return 0;
}