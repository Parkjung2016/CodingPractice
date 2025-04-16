#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace   std;
#define  MAX 1001
int arr[MAX][MAX];

int dist[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;
	dist[y][x] = 0;
	while (!q.empty())
	{
		pair<int, int> pair = q.front();
		q.pop();
		y = pair.first;
		x = pair.second;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx] == 1 && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				dist[ny][nx] = dist[y][x] + 1;
				q.emplace(ny, nx);
			}
		}
	}
}
int main()
{


	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				dist[i][j] = 0;
			else dist[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 2)
			{
				bfs(i, j);
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}