#include <iostream>
#include <cstring>
using namespace  std;

int arr[102][102];
bool visited[102][102];
int maxHeight = -1;

int cnt;

int maxSafePlace = -1;

int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,-1,1 };
int n;

void dfs(int i, int j, int rain)
{
	for (int x = 0; x < 4; x++)
	{
		int nx = i + dirx[x];
		int ny = j + diry[x];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] <= rain || visited[nx][ny])continue;
		visited[nx][ny] = true;
		dfs(nx, ny, rain);

	}
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			maxHeight = max(maxHeight, arr[i][j]);
		}
	}


	for (int rain = 0; rain <= maxHeight; rain++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && arr[i][j] > rain)
				{
					cnt++;
					dfs(i, j, rain);
				}
				else
					visited[i][j] = true;
			}
		}
		maxSafePlace = max(maxSafePlace, cnt);
	}

	cout << maxSafePlace;
}