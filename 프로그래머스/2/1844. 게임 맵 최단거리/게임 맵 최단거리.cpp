#include<vector>
#include <queue>
using namespace std;

int row, col;
int visited[101][101];

queue<pair<int, int>>que;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int solution(vector<vector<int> > maps)
{
	int row = maps.size();
	int col = maps[0].size();
	que.emplace(0, 0);
	visited[row][col] = 1;
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i]; // row 행사이즈, col 열사이즈
			if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
			if (maps[nx][ny] == 1 && visited[nx][ny] == 0)
			{
        
				que.emplace(nx, ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}

if(visited[row-1][col-1] != 0) return visited[row-1][col-1]+1;
    return -1;
}