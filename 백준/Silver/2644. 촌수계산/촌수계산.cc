#include <iostream>
#include <queue>
#include <climits>
#define MAX  102
using  namespace std;


int arr[MAX][MAX];
int visited[MAX];
int n, k;

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (arr[v][i] == 1 && !visited[i])
			{
				visited[i] = visited[v] + 1;
				q.push(i);
			}

		}
	}

}
int main()
{
	int targetX, targetY;
	cin >> n;
	cin >> targetX >> targetY;
	cin >> k;


	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bfs(targetX);
	if (visited[targetY] == 0)
		visited[targetY] = -1;

	cout << visited[targetY];


}