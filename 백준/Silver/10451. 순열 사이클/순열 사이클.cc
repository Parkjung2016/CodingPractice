#include <iostream>
#include <cstring>
#include <vector>

std::vector<int> vec[1001];
bool visited[1001];
using namespace  std;


void dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < vec[v].size(); i++)
	{
		int a = vec[v][i];
		if (!visited[a])
		{
			dfs(a);
		}
	}
}
int main()
{
	int t;

	cin >> t;


	for (int i = 0; i < t; i++)
	{
		int n;

		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			vec[j].clear();
			visited[j] = false;
		}
		for (int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;
			vec[j].push_back(num);
		}
		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j])
			{
				count++;
				dfs(j);
			}
		}
		cout << count << endl;
	}
}