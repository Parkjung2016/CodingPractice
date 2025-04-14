#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
using namespace std;

#define MAX 1001
int arr[MAX][MAX];
bool visited[MAX];
int n, m;

void dfs(int v)
{
	cout << v << " ";
	visited[v] = true;

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
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int v;
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
	memset(visited, false, sizeof(visited));
	bfs(v);

}