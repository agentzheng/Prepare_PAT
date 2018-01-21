#include<iostream>
#include<string>
using namespace std;
int main()
{
	string match[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	string str;
	cin >> str;
	int sum = 0;
	for (string::iterator it = str.begin(); it != str.end(); it++)
		sum += *it - '0';
	string sum_string = to_string(sum);
	for (int i=0;i<sum_string.length();i++)
	{
		cout << match[(sum_string[i] - '0')];
		if (i != sum_string.length() - 1)
			cout << ' ';
		else
			cout << endl;
	}

	return 0;
}