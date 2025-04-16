#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#define MAX 100001
using namespace std;
bool visited[MAX];

int dist[MAX];

int prevNum[MAX];
int main()
{
	memset(dist, -1, sizeof(dist));
	memset(prevNum, -1, sizeof(prevNum));
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	visited[n] = true;
	dist[n] = 0;

	while (!q.empty())
	{
		int  num = q.front();
		q.pop();

		if (num == m) break;
		for (int next : {num - 1, num + 1, num * 2}) {
			if (next >= 0 && next < MAX && dist[next] == -1) {  // dist[next] == -1이면 방문한 적 없는 곳
				dist[next] = dist[num] + 1;
				prevNum[next] = num;
				q.push(next);
			}
		}
	}

	cout << dist[m] << "\n";

	vector<int > v;

	for (int i = m; i != -1; i = prevNum[i])
	{
		v.push_back(i);
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}
