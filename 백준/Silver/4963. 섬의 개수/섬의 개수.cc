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
#define  MAX 51

int w = -1, h = -1;


int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1,1,0,0 ,-1,-1,1 ,1 };
int dy[] = { 0,0,-1,1,-1,1,1,-1 };


void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> pair = q.front();
		q.pop();

		y = pair.first;
		x = pair.second;

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h && arr[ny][nx] == 1 && !visited[ny][nx])
			{
				q.emplace(ny, nx);
				visited[ny][nx] = true;
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 || h == 0)break;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		int result = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					bfs(i, j);
					result++;
				}
			}
		}
		cout << result << "\n";

	}
}