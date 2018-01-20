#include<iostream>
#include<string>
#include<vector>
#include<vld.h>
using namespace std;

struct Node
{
	string ID;
	vector<string> child;
};

vector<Node>::iterator finds(vector<Node>& nodes,string ID)
{
	for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		if (it->ID == ID)
			return it;
	}
	return nodes.end();
}


void form(vector<Node>& nodes, vector<Node>::iterator it, int level,vector<int>& count)
{
	if (level == count.size())
		count.push_back(0);
	if (level + 1 == count.size())
		count.push_back(0);
	for (vector<string>::iterator it2 = it->child.begin(); it2 != it->child.end(); it2++)
	{
		vector<Node>::iterator it3 = finds(nodes, *it2);
		if (it3 == nodes.end())
			count[level + 1]++;
		else
			form(nodes, it3, level + 1, count);
	}
}



int main()
{
	//约定 当输进去的值是一个 -1时，表示当前的这一层遍历结束。
	int N = 0, M = 0;
	cin >> N >> M;
	vector<Node> nodes;
	for (int i = 0; i < M; i++)
	{
		Node temp;
		int k = 0;
		cin >> temp.ID;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			string ID = "";
			cin >> ID;
			temp.child.push_back(ID);
		}
		nodes.push_back(temp);
	}
	int level = 0;
	vector<Node>::iterator it = finds(nodes, "01");
	vector<int>count;
	form(nodes, it, 0, count);
	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i];
		if (i != count.size()-1)
			cout << ' ';
		else
			cout << endl;
	}

	return 0;

}

/*
7 4
01 2 02 03
02 1 04
03 2 05 06
05 1 07









5 4
01 1 02
02 1 03
03 1 04
04 1 05
*/