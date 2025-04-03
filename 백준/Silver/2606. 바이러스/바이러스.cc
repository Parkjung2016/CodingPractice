#include <iostream>
#include <queue>
#define MAX  101
using  namespace std;

int arr[MAX][MAX];
bool visited[MAX];
int countNum;
int n, k;

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[v][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
				countNum++;
			}
		}
	}
}
int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	bfs(1);

	cout << countNum;

}