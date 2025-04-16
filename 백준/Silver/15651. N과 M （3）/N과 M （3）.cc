#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace   std;
#define  MAX 9
bool visited[MAX];
int arr[MAX] = { 0, };
int n, m;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';

		}
		cout << "\n";
		return;

	}

	for (int i = 1; i <= n; i++)
	{
		//if (!visited[i])
		//{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		//}
	}
}
int main()
{
	cin >> n >> m;
	dfs(0);
	return 0;
}