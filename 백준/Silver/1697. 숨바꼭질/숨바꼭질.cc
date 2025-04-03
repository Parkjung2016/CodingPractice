#include <iostream>
#include <queue>
using namespace  std;
#define  MAX 100001
int n, k;

bool visited[MAX];
queue<pair<int, int>>q;

void UpdateVisited(int target, int y)
{
	if (target >= 0 && target <= MAX)
	{
		if (!visited[target])
		{
			visited[target] = true;
			q.emplace(target, y + 1);
		}
	}
}
void bfs()
{
	q.emplace(n, 0);
	while (!q.empty())
	{
		pair<int, int> pair = q.front();
		int x = pair.first;
		int y = pair.second;
		q.pop();


		if (x == k)
		{
			cout << y;
			break;
		}

		UpdateVisited(x + 1, y);
		UpdateVisited(x - 1, y);
		UpdateVisited(x * 2, y);
	}
}

int main()
{
	cin >> n >> k;
	bfs();
}