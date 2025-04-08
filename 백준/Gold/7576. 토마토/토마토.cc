#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;
#define MAX 1001
int arr[MAX][MAX];
struct	Node
{
	int y, x;
};
queue<Node> q;

int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,-1,1 };
int m, n;

bool IsInRange(int x, int y)
{
	return x >= 0 && y >= 0 && x < m && y < n;
}
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
			int nx = x + dirx[i];
			int ny = y + diry[i];

			if (IsInRange(nx, ny) && arr[ny][nx] == 0)
			{
				arr[ny][nx] = arr[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}
int main()
{
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
			}
		}
	}
	bfs();
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			result = max(result, arr[i][j]);
		}

	}
	cout << result - 1;
}
