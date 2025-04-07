#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#include <iostream>
#include <queue>
#define MAX 25
using namespace std;

string arr[MAX];

bool visited[MAX][MAX];

int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,-1,1 };
int	n;
int cnt;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.emplace(x, y);
	visited[x][y] = true;
	cnt++;
	while (!q.empty())
	{
		pair<int, int> pair = q.front();
		q.pop();
		int a = pair.first;
		int b = pair.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = a + dirx[i];
			int ny = b + diry[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == '0' || visited[nx][ny])continue;;

			visited[nx][ny] = true;
			q.emplace(nx, ny);
			cnt++;
		}
	}
}
int main()
{

	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1' && !visited[i][j])
			{
				cnt = 0;
				bfs(i, j);
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}

}