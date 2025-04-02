#include <iostream>
#include <cstring>
#include <queue>

using namespace  std;

int n, m;

int arr[2000][2000];
bool visited[2000];

int countNum = 0;
void dfs(int v)
{
	visited[v] = true;

	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] == 1 && !visited[i])
		{
			dfs(i);
		}
	}

}
int main()
{

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			countNum++;
			dfs(i);
		}
	}
	cout << countNum << "\n";

}