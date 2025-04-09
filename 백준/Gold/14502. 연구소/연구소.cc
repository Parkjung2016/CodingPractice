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
#define  MAX 9

int arr[MAX][MAX];
int n, m;

int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,-1,1 };
struct Node
{
	int y, x;
};
queue<Node> q;

int result = 0;
void spreadVirus()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}
	int copyArr[MAX][MAX];
	memcpy(copyArr, arr, sizeof(arr));
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

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && copyArr[ny][nx] == 0)
			{
				copyArr[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copyArr[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	result = max(result, cnt);

}
void makeWall(int placeWallCount)
{
	if (placeWallCount == 3)
	{
		spreadVirus();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				makeWall(placeWallCount + 1);
				arr[i][j] = 0;
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num = 0;
			cin >> num;
			arr[i][j] = num;
		}
	}

	makeWall(0);

	cout << result;
}