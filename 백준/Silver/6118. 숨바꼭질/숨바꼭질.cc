#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

#define MAX 50001

int dist[MAX];
bool visited[MAX];
vector<int> arr[MAX];

void bfs()
{
	queue<int> q;

	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : arr[now])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


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
	int maxDis = 0;
	for (int i = 1; i <= n; i++)
	{
		maxDis = max(maxDis, dist[i]);
	}

	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
	{
		if (maxDis == dist[i])
		{
			v.push_back({ i, dist[i] });
		}
	}


	if (v.size() == 1)
	{
		cout << v[0].first << " " << v[0].second;
	}
	else
	{
		sort(v.begin(), v.end());
		cout << v[0].first << " " << v[0].second;
	}
	cout << " " << v.size();
	return 0;
}