#include<algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace  std;
int n, m, v;

int arr[1001][1001];
bool visited[1001];

void dfs(int v)
{
	visited[v] = true;

	cout << v << " ";

	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] && !visited[i])
		{
			dfs(i);
		}

		if (i == n)return;
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		int next = q.front();
		visited[next] = true;
		q.pop();

		cout << next << " ";

		for (int i = 1; i <= n; i++)
		{
			if (arr[next][i] && !visited[i])
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
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	bfs(v);
}