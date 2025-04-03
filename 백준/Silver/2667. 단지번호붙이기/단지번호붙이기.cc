#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define  MAX 26
using namespace  std;

string arr[MAX];
bool visited[MAX][MAX];
int n;

int cnt;


int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,-1,1 };
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.emplace(x, y);

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

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == '0' || visited[nx][ny])continue;

			q.emplace(nx, ny);
			visited[nx][ny] = true;
			cnt++;
		}
	}
}
int main()
{

	vector<int> vec;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1' && !visited[i][j])
			{
				cnt = 1;
				visited[i][j] = true;
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
