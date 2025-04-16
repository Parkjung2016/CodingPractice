#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define MAX 101
using namespace std;

vector<int> arr[MAX];
bool visited[MAX];
int compCount;
void bfs()
{
	queue <int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int i = 0; i < arr[num].size(); i++)
		{
			int next = arr[num][i];

			if (!visited[next])
			{
				compCount++;
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	bfs();

	cout << compCount;
	return 0;
}
