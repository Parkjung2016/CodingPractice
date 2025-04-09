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

string arr[MAX];
int dist[MAX][MAX][2];
bool visited[MAX][MAX][2];
int n, m;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node
{
	int y, x;
	bool breakWall;
};
void bfs()
{
	queue<Node> q;
	q.push({ 0,0,false });
	visited[0][0][0] = true;
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		auto [y, x, breakWall] = q.front();

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (arr[ny][nx] == '0' && !visited[ny][nx][breakWall])
				{
					visited[ny][nx][breakWall] = true;

					dist[ny][nx][breakWall] = dist[y][x][breakWall] + 1;
					q.push({ ny,nx,breakWall });
				}
				else if (arr[ny][nx] == '1' && !breakWall && !visited[ny][nx][1])
				{
					visited[ny][nx][1] = true;
					dist[ny][nx][1] = dist[y][x][0] + 1;
					q.push({ ny,nx,true });
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	bfs();

	int noBreak = dist[n - 1][m - 1][0];
	int breaked = dist[n - 1][m - 1][1];

	if (noBreak == 0 && breaked == 0)cout << -1;
	else if (noBreak == 0)cout << breaked;
	else if (breaked == 0)cout << noBreak;
	else cout << min(noBreak, breaked);

}