#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

#define MAX 51

int parent[MAX];
vector<int> tree[MAX];
int removeNode;
int leafCount;

void dfs(int node)
{
	if (node == removeNode)return;

	bool isLeaf = true;

	for (int child : tree[node])
	{
		if (child != removeNode)
		{
			dfs(child);
			isLeaf = false;
		}
	}
	if (isLeaf)leafCount++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int index = 0;

	int root = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> parent[i];
		if (parent[i] == -1)
		{
			root = i;
		}

		else
		{
			tree[parent[i]].push_back(i);
		}
	}

	cin >> removeNode;

	if (removeNode == root)
	{
		cout << 0;

	}
	else
	{
		dfs(root);
		cout << leafCount;
	}
}