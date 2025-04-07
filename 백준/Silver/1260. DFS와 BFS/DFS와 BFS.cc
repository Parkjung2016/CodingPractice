#include <queue>
#include <cstring>
#include <iostream>
#include <queue>
#define  MAX 1001
using namespace std;

int n, m, v;
int arr[MAX][MAX];
bool visited[MAX];
void dfs(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] == 1 && !visited[i])
			dfs(i);
	}
}
void bfs(int v)
{
	queue<int>	q;
	q.push(v);
	visited[v] = true;
	cout << v << " ";
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

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << "\n";
	bfs(v);
}