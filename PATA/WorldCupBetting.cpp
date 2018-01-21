#include<iostream>
#include<vector>
#include <iomanip>
#include<stdio.h>
using namespace std;


struct Node
{
	char re;
	double weight;
};

int main()
{
	const char * str = "WTL";
	int count = 0;
	vector<Node> maxs;
	float arr[3];
	for(int i=0;i<3;i++)
	{
		cin >> arr[0] >> arr[1] >>arr[2];
		int maxi = 0;
		for(int i=1;i<3;i++)
		{
			if (arr[maxi] < arr[i])
				maxi = i;
		}
		maxs.push_back({ str[maxi],arr[maxi] });
	}
	float result = 1;
	for (vector<Node>::iterator it = maxs.begin(); it != maxs.end(); it++)
	{
		cout << it->re << ' ';
		result *= it->weight;
	}
	result = ((result * 650)/1000 - 1);
	result *= 2;
	//result = result * 100+0.5;
	//int ceil = result;
	
	result /= 100.0;

	cout << setprecision(2) << result << endl;



	return 0;
}