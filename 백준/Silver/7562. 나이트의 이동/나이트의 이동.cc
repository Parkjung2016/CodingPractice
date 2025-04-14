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

#define MAX 301
int arr[MAX][MAX];
bool visited[MAX][MAX];
int moveY, moveX;
int l;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

struct Node
{
	int y, x;
};
void bfs(int x, int y)
{
	queue<Node> q;
	q.push({ y,x });
	arr[y][x] = 0;
	visited[y][x] = true;
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		x = node.x;
		y = node.y;
		if (x == moveX && y == moveY)return;
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				arr[ny][nx] = arr[y][x] + 1;
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

	int t;
	cin >> t;
	while (t--)
	{
		cin >> l;
		int startX, startY;

		cin >> startY >> startX;
		cin >> moveY >> moveX;
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		bfs(startX, startY);
		cout << arr[moveY][moveX] << "\n";
	}
}