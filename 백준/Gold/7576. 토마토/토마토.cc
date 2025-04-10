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
#define  MAX 1001
int arr[MAX][MAX];
int dist[MAX][MAX];
int m, n;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node
{
	int y, x;
};
queue<Node> q;
int result;

void bfs()
{
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx] == 0)
			{
				arr[ny][nx] = 1;
				dist[ny][nx] = dist[y][x] + 1;

				q.push({ ny,nx });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			arr[i][j] = num;
			if (num == 1)
			{
				q.push({ i,j });
				dist[i][j] = 1;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			result = max(result, dist[i][j]);
		}
	}
	cout << result - 1;
}