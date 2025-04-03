#include <queue>
#include <cstring>
#include <iostream>
#define  MAX 1001
using namespace std;


int arr[MAX][MAX];
bool visited[MAX];
int n;
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
	}
}

void bfs(int v)
{
	queue<int> q;
	visited[v] = true;
	cout << v << " ";
	q.push(v);

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (arr[v][i] == 1 && !visited[i])
			{
				visited[i] = true;
				cout << i << " ";
				q.push(i);
			}

		}
	}
}
int main()
{
	int m, v;

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