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
#define  MAX 101
int dz[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dx[] = { -1,1,0,0,0,0 };

int m, n, h;

int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

struct Node
{
	int z, y, x;
};
queue<Node> q;
void bfs()
{
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();
		int z = node.z;
		int y = node.y;
		int x = node.x;
		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nz >= 0 && ny >= 0 && nx >= 0 && nz < h && ny < n && nx < m && arr[nz][ny][nx] == 0 && !visited[nz][ny][nx])
			{
				visited[nz][ny][nx] = true;
				q.push({ nz,ny,nx });
				arr[nz][ny][nx] = arr[z][y][x] + 1;
			}
		}
	}

}
int main()
{
	cin >> m >> n >> h;
	int cnt = 0;

	for (int x = 0; x < h; x++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int num;
				cin >> num;
				arr[x][i][j] = num;

				if (num == 1)
				{
					q.push({ x,i,j });
				}
			}
		}
	}


	bfs();
	int maxNum = 0;
	for (int x = 0; x < h; x++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[x][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
				else
				{
					maxNum = max(maxNum, arr[x][i][j]);
				}
			}
		}
	}
	cout << maxNum-1;

}