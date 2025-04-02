#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

int n, m, v;

using namespace  std;
int arr[1001][1001];
bool visited[1001];

void dfs(int v)
{
	visited[v] = true;

	cout << v << " ";

	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] == 1 && !visited[i])
		{
			dfs(i);
		}

		if (n == i)return;
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		int num = q.front();
		visited[num] = true;
		q.pop();
		cout << num << " ";

		for (int i = 1; i <= n; i++)
		{
			if (arr[num][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main()
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(v);
	cout << " ";
	for (int i = 0; i < 1001; i++)
		memset(visited, 0, sizeof(visited));

	bfs(v);
}