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

string arr[MAX];
int n;

bool visited[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs(int y, int x, char c)
{
	queue<pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;

	while (!q.empty())
	{
		pair<int, int>pair = q.front();
		q.pop();

		y = pair.first;
		x = pair.second;

		visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && nx < n && ny < n && arr[ny][nx] == c && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.emplace(ny, nx);

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R' && !visited[i][j])
			{
				cnt++;
				bfs(i, j, 'R');
			}
			else if (arr[i][j] == 'G' && !visited[i][j])
			{
				cnt++;
				bfs(i, j, 'G');
			}
			else if (arr[i][j] == 'B' && !visited[i][j])
			{
				cnt++;
				bfs(i, j, 'B');
			}
		}
	}

	cout << cnt << "\n";
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'G')
			{
				arr[i][j] = 'R';
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R' && !visited[i][j])
			{
				cnt++;
				bfs(i, j, 'R');
			}
			else if (arr[i][j] == 'B' && !visited[i][j])
			{
				cnt++;
				bfs(i, j, 'B');
			}
		}
	}
	cout << cnt;



}