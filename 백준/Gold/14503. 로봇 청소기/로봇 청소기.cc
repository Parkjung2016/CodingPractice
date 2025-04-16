#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define MAX 51
using namespace std;

int arr[MAX][MAX];

int boardCount;

int dx[] = { 0, 1,0, -1 };
int dy[] = { -1, 0,1,0 };
int main()
{
	int n, m;
	cin >> n >> m;

	int y, x, dir;
	cin >> y >> x >> dir;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (true)
	{
		if (arr[y][x] == 0)
		{
			arr[y][x] = 2;
			boardCount++;
		}

		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx] == 0)
			{
				check = true;
				break;

			}
		}
		if (!check)
		{
			int backDir = (dir + 2) % 4;
			int nx = x + (dx[backDir]);
			int ny = y + (dy[backDir]);
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (arr[ny][nx] == 1)
					break;
				x = nx;
				y = ny;
			}

		}
		else
		{
			bool moved = false;
			for (int i = 0; i < 4; i++)
			{
				dir = (dir + 3) % 4;
				int	nx = x + dx[dir];
				int	ny = y + dy[dir];
				if (nx >= 0 && ny >= 0 && nx < m && ny < n)
				{
					if (arr[ny][nx] == 0)
					{
						x = nx;
						y = ny;
						moved = true;
						break;
					}
				}
			}

			if (!moved)
			{
				int backDir = (dir + 2) % 4;
				int nx = x + (dx[backDir]);
				int ny = y + (dy[backDir]);
				if (nx >= 0 && ny >= 0 && nx < m && ny < n)
				{
					if (arr[ny][nx] == 1)
						break;
					x = nx;
					y = ny;
				}
				else break;
			}

		}
	}
	cout << boardCount;

	return 0;
}
