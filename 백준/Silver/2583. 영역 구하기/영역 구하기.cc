#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

#define MAX 101

int m, n;

bool visited[MAX][MAX];
int arr[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int bfs(int y, int x)
{
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.emplace(y, x);
	int result = 1;
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
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[ny][nx] == 0 && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.emplace(ny, nx);
				result++;
			}
		}
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;
	cin >> m >> n >> k;
	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				arr[i][j] = 1;
			}
		}

	}
	vector<int> rangeVec;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && !visited[i][j])
			{
				int size = bfs(i, j);
				rangeVec.push_back(size);
			}
		}
	}
	cout << rangeVec.size() << "\n";
	sort(rangeVec.begin(), rangeVec.end());
	for (int i : rangeVec)
	{
		cout << i << " ";
	}
	return 0;
}