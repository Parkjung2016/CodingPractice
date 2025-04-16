#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#define MAX 1004
using namespace std;
string str[MAX];
bool visisted[MAX][MAX];
int main()
{

	int n;
	cin >> n;

	int headX = 0, headY = 0;
	int x = -1, y = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];

		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == '*')
			{
				if (x == -1)
				{
					headX = j;
					headY = i;
					x = j + 1;
					y = i;
				}
			}
		}


	}

	y += 1;

	cout << y << " " << x << "\n";

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	vector<int > v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == y && j == x - 1)continue;
			if (i == headY && j == headX)continue;

			if (str[i][j] == '*' && !visisted[i][j])
			{
				int result = 0;
				queue<pair<int, int>> q;
				q.push({ i,j });
				result = 1;
				visisted[i][j] = true;
				while (!q.empty())
				{
					pair<int, int> pair = q.front();
					q.pop();
					int ax = pair.second;
					int ay = pair.first;
					for (int k = 0; k < 4; k++)
					{
						int nx = ax + dx[k];
						int ny = ay + dy[k];

						if (nx >= 0 && ny >= 0 && nx <= n && ny <= n && str[ny][nx] == '*' && !visisted[ny][nx])
						{
							if (ny == y && nx == x - 1)continue;

							visisted[ny][nx] = true;
							result++;
							q.emplace(ny, nx);
						}
					}
				}

				v.push_back(result);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;

}
